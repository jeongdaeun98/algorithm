#include <string>
#include <vector>
#include <stack>

using namespace std;
bool visited[200];
void initVisited(int n){
    for(int i = 0; i < n; i++){
            visited[i] = 0;
    }
}


int solution(int n, vector<vector<int>> computers) {
    initVisited(n);
    int answer = 0;
    stack<int> stack;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            answer++;
            stack.push(i);
            visited[i] = true;
        }
    while(!stack.empty()){
        int node = stack.top();
            for(int j = 0; j < computers[node].size(); j++){
                if(computers[node][j] == 1 && !visited[j]){
                    stack.push(j);
                    visited[j] = true;
                    break;
                }
            }
        if(stack.top() == node)
            stack.pop();
    }
    }
    return answer;
}