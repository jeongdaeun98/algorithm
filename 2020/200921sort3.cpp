#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    priority_queue<int> pq;
    sort(citations.begin(), citations.end());
    while(1){
        answer++;
        int upperCount = 0, underCount = 0;
        for(int i = 0; i < citations.size(); i++){
            if(answer <= citations[i]){
                ++upperCount;
            }
        }
        if(upperCount < answer){
            break;
        }
    }
    return answer - 1;
}