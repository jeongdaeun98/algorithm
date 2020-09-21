#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    int answer = 0;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i],i));
    }
    while(1){
        if(pq.top() == q.front().first){
            answer++;
            if(location == q.front().second) return answer;
            pq.pop();
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
        
    }
}