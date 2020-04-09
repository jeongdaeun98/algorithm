#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue <int,vector<int>,greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(!pq.empty()){
        if(K <= pq.top()) return answer;
        int mix = pq.top();
        pq.pop();
        if(!pq.empty()){
            answer++;
            mix += pq.top()*2;
            pq.pop();
            pq.push(mix);
        }
        else return -1;

    }
    return -1;
}