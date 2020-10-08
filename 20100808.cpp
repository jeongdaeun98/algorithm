#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long right = times[times.size() - 1];
    right *= n;
    long long answer = right, left = 0, mid = 0;
    
    while(right >= left){
        long long workCount = 0;
        mid = (right + left) / 2;
        for(int time : times){
            workCount += mid / time;
        }
        if(workCount < n){
            left = mid + 1;
        }
        else {
            if(answer > mid)
                answer = mid;
            right = mid - 1;
        }
    }
    return answer;
}