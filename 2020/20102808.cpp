#include <iostream>
#include <vector>

using namespace std;

vector<int> friendVector[2000];
int visited[2000];
int n;
bool isFour = false;
void initVisited(){
    for(int i = 0; i <n; i++){
        visited[i] = false;
    }
}
void dfs(int depth, int y){
    visited[y] = true;
    if(depth == 4){
        cout << 1;
        isFour = true;
        return;
    }
    for(int i = 0; i < friendVector[y].size(); i++){
        if(!visited[friendVector[y][i]])
            dfs(depth + 1, friendVector[y][i]);
    }
    visited[y] = false;
}
int main(void){
    int count;
    cin >> n >> count;
    for(int i = 0; i < count; i++){
        int a, b;
        cin >> a >> b;
        friendVector[a].push_back(b);
        friendVector[b].push_back(a);
    }
    initVisited();
    for(int i = 0; i < n; i++){
        dfs(0, i);
        if(isFour) break;
    }
    if(!isFour) cout << 0;
}