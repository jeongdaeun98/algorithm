//외판원 순회 2
#include <iostream>
using namespace std;
int visited[11];
int path[11][11];
int n, minSum = 987654321;
void dfs(int start, int target, int y, int sum){
    if(start == y && target == n){
        if(sum < minSum){
            minSum = sum;
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[y] == 1 || path[y][i] == 0) continue;
        if(sum < minSum){
            visited[y] = 1;
            dfs(start, target + 1, i, sum + path[y][i]);
            visited[y] = 0;
        }
    }
}
int main(void){
    cin >> n;
    fill_n(visited,11,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> path[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        dfs(i, 0, i, 0);
    }
    cout << minSum;
}