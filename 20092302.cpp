#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    for(int i = 0; i < reserve.size();){
        vector<int>:: iterator lostIter  = find(lost.begin(), lost.end(), reserve[i]);
        if(lostIter != lost.end()){
            lost.erase(lostIter);
            reserve.erase(reserve.begin() + i);
        }
        else {
            i++;
        }
    }
    int answer = n - lost.size();
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    
    bool eraseTrue = false;
    for(int i = 0; i < reserve.size();){
        for(int j = 0; j < lost.size();){
            if(reserve[i] == lost[j] + 1 || reserve[i] == lost[j] - 1){
                lost.erase(lost.begin() + j);
                answer++;
                eraseTrue = true;
                break;
            }
            else{
                j++;
            }
        }
        if(eraseTrue) reserve.erase(reserve.begin() + i);
        else i++;
        eraseTrue = false;
    }
    return answer;
}