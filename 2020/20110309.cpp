//작업
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> job[10001];
int jobTime[10001];
int afterTime[10001];
int degree[10001] = {0};
int answer = 0;
void topologySort(int n){
    queue<int> q;
    int maxTime = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    for(int i = 1; i <= n; i++){
        maxTime = 0;
        int work = q.front();
        q.pop();
        for(int j = 0; j < job[work].size(); j++){
            int next = job[work][j];
            afterTime[next] = max(afterTime[next], afterTime[work] + jobTime[next]);
            if(--degree[job[work][j]] == 0){
                q.push(next);
            }
        }
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> jobTime[i];
        afterTime[i] = jobTime[i];
        int relatedNum;
        cin >> relatedNum;
        for(int j = 0; j < relatedNum; j++){
            int num;
            cin >> num;
            job[i].push_back(num);
            degree[num]++;
        }
    }
    topologySort(n);
    for(int i = 1; i <= n; i++){
        answer = max(answer, afterTime[i]);
    }
    cout << answer;
}