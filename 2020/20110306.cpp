//문제집
#include <iostream>
#include <queue>
using namespace std;

vector<int> problem[32001];
int degree[32001] = {0};
void topologySort(int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) pq.push(i);
    }
    for(int i = 1; i <= n; i++){
        int solvingProblem = pq.top();
        cout << solvingProblem << " ";
        pq.pop();
        for(int j = 0; j < problem[solvingProblem].size(); j++){
            if(--degree[problem[solvingProblem][j]] == 0){
                pq.push(problem[solvingProblem][j]);
            }
        }
    }

}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int problem1, problem2;
        cin >> problem1 >> problem2;
        problem[problem1].push_back(problem2);
        degree[problem2]++;
    }
    topologySort(n);
}