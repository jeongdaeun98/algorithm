#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,presentWeight = weight;
    queue<int> q;
    for(int truck : truck_weights)
        q.push(truck);

    vector<pair<int,int>> truckInfo;
    while(!q.empty() || !truckInfo.empty()){
        answer++;
        for(int i = 0; i < truckInfo.size();){
            truckInfo[i].second--;
            if(truckInfo[i].second == 0){
                presentWeight += truckInfo[i].first;
                truckInfo.erase(truckInfo.begin() + i);
            }
            else i++;
        }
        if(!q.empty() && presentWeight >= q.front()){
            presentWeight -= q.front();
            truckInfo.push_back(make_pair(q.front(),bridge_length));
            q.pop();
        }
    }
    return answer;
}