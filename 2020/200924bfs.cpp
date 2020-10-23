#include <iostream>
#include <queue>
using namespace std;

int computer[101][101];
int bfs(int num){
    int bfsCount = 0;
    bool *checkArray = new bool[num];
    for(int i = 0; i < num; i++){
        checkArray[i] = false;
    }
    queue<int> q;
    q.push(0);
    checkArray[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < num; i++){
            if(!checkArray[i] && computer[node][i] == 1){
                q.push(i);
                checkArray[i] = true;
                bfsCount++;
            }
        }
    }
    return bfsCount;
}
int main(void){
    int num, m;
    cin >> num >> m;
    for(int i = 0 ; i < m; i++){
        int a,b;
        cin >> a >> b;
        computer[a - 1][b - 1] = 1;
        computer[b - 1][a - 1] = 1;
    }
    cout << bfs(num);
}