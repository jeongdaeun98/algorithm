#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    queue<pair<int,int>> q;

    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i],i));
    }
    while(!q.empty()){
        if(q.front().first == pq.top()){
            if(location == q.front().second)
                return answer;
            pq.pop();
            q.pop();
            answer++;
        }
        else{
            pair<int,int> num = q.front();
            q.pop();
            q.push(num);
        }
    }
}