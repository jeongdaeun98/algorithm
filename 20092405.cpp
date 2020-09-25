#include <iostream>
#include <string>
#include <queue>
using namespace std;

int **vertex;
int **checked;
int **weight;
int directX[] = {0,0,1,-1};
int directY[] = {1,-1,0,0};
void initChecked(int m, int n){
    checked = new int*[m];
    for(int i = 0; i < m; i++){
        checked[i] = new int[n];
        for(int j = 0; j < n; j++){
            checked[i][j] = false;
        }
    }
}
void initVertex(int m, int n){
    vertex = new int*[m];
    for(int i = 0; i < m; i++){
        vertex[i] = new int[n];
        string dotStr;
        cin >> dotStr;
        for(int j = 0; j < n; j++){
            vertex[i][j] = dotStr[j] - '0';
        }
    }
}
void initWeight(int m, int n){
    weight = new int*[m];
    for(int i = 0; i < m; i++){
        weight[i] = new int[n];
        for(int j = 0; j < n; j++){
            weight[i][j] = 0;
        }
    }
}
int bfs(int m, int n){
    queue<pair<int, int> > q;
    checked[0][0] = true;
    q.push(make_pair(0,0));
    weight[0][0] = 1;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = node.first + directX[i];
            int dy = node.second + directY[i];
            if(dx >= 0 && dy >= 0 && dx < m && dy < n && !checked[dx][dy] && vertex[dx][dy] == 1){
                q.push(make_pair(dx,dy));
                checked[dx][dy] = true;
                weight[dx][dy] += weight[node.first][node.second] + 1;
            }
        }
    }
    return weight[m - 1][n - 1];
}
int main(void){
    int m, n;
    cin >> m >> n;
    initChecked(m, n);
    initVertex(m, n);
    initWeight(m, n);
    cout << bfs(m,n);

}