#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, copyWeight = weight;
    vector<int> remainTime;
    queue<int> q, ridingQ;
    for(int i = 0; i < truck_weights.size(); i++){
        q.push(truck_weights[i]);
    }
    while(!q.empty() || !ridingQ.empty()) {
        answer++;
        for(int i = 0; i < remainTime.size(); i++){
            remainTime[i]--;
        }
        if(!remainTime.empty()&&remainTime[0] == 0 && !ridingQ.empty()){
            copyWeight += ridingQ.front();
            remainTime.erase(remainTime.begin());
            ridingQ.pop();
        }
        if(!q.empty() && copyWeight >= q.front()){
            copyWeight -= q.front();
            remainTime.push_back(bridge_length);
            ridingQ.push(q.front());
            q.pop();
        }
    }
    return answer;
}