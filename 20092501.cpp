#include <iostream>
#include <queue>
using namespace std;

int box[1000][1000];
int weight[1000][1000];
queue<pair<int, int> > q;
int directX[] = {0,0,1,-1};
int directY[] = {1,-1,0,0};
void initBox(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }
}
void initWeight(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            weight[i][j] = 0;
        }
    }
}
int bfs(int m, int n){
    int maxWeight = 0;
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = node.first + directX[i];
            int dy = node.second + directY[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && !weight[dx][dy] && box[dx][dy] == 0){
                q.push(make_pair(dx, dy));
                box[dx][dy] = 2;
                weight[dx][dy] += weight[node.first][node.second] + 1;
                if(weight[dx][dy] > maxWeight) maxWeight = weight[dx][dy];
            }
        }
    }
    return maxWeight;
}
bool print(int m, int n) {
    bool printNo = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(box[i][j] == 0) printNo = true;
        }
    }
    return printNo;
}
int main(void){
    int n, m;
    cin >> n >> m;
    initBox(m, n);
    initWeight(m, n);
    int result = bfs(m,n);
    if(print(m, n)) cout << -1;
    else cout << result;

}