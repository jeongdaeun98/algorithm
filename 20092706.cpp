#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool checked[200];
void initChecked(int n){
    for(int i = 0; i < n; i++){
        checked[i] = false;
    }
}
void dfs(vector<vector<int>> computers, int start, int n){
    stack<int> stack;
    stack.push(start);
    checked[0] = true;
    while(!stack.empty()){
        int node = stack.top();
        stack.pop();
        for(int i = 0; i < n; i++){
            if(!checked[i] && computers[node][i] == 1){
                stack.push(node);
                stack.push(i);
                checked[i] = true;
                break;
            }
        }
    }
}
int searchDfs(vector<vector<int>> computers, int n){
    int networkCount = 0;
    for(int i = 0; i < n; i++){
        if(!checked[i]){
            dfs(computers,i, n);
            networkCount++;
        }
    }
    return networkCount;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    initChecked(n);
    answer = searchDfs(computers, n);
    return answer;
}