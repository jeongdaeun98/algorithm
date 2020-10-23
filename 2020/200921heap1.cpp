#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(1){
        if(!pq.empty() && pq.top() >= K) return answer;
        if(pq.size() < 2) break;
        int minScoville = pq.top();
        pq.pop();
        int twoMinScoville = pq.top();
        pq.pop();
        pq.push(minScoville + twoMinScoville*2);
        answer++;
    }
    answer = -1;
    return answer;
}