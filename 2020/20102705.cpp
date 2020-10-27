#include <iostream>
using namespace std;

int directx[] = {0,0,1,-1};
int directy[] = {1,-1,0,0};
int termino[4][4][2] = {
    {{0,0},{0,1},{0,2},{1,1}},
    {{1,0},{0,1},{1,1},{2,1}},
    {{0,0},{1,0},{1,1},{2,0}},
    {{0,1},{1,0},{1,1},{1,2}}
};
int maxWeight = 0;
bool visited[501][501];
int vertex[501][501];
int n,m;
void initVisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }
}
void initVertex(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> vertex[i][j];
        }
    }
}
void dfs(int count, int y, int x, int sum){
    if(count == 3){
        if(maxWeight < sum) maxWeight = sum;
        return;
    }
    for(int i = 0; i < 4; i++){
        int dx = directx[i] + x;
        int dy = directy[i] + y;
        if(dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dy][dx]){
            visited[dy][dx] = true;
            dfs(count + 1, dy, dx, sum + vertex[dy][dx]);
            visited[dy][dx] = false;
        }
    }
}
bool isTerminoInVertex(int x, int y, int k){
    for(int i = 0; i < 4; i++){
      if(!(x + termino[k][i][1] < m && y + termino[k][i][0] < n))
        return false;
    }
    return true;
}
void moveTermino(int y, int x){
   for(int i = 0; i < 4; i++){
        if(isTerminoInVertex(x,y,i)){
            int sumNumber = 0;
            for(int j = 0; j < 4; j++){
                sumNumber += vertex[y + termino[i][j][0]][x + termino[i][j][1]];
            }
            if(sumNumber > maxWeight) maxWeight = sumNumber;
        }
    }
}
void search(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            dfs(0, i, j,vertex[i][j]);
            visited[i][j] = false;
            moveTermino(i,j);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    initVertex();
    initVisited();
    search();
    cout << maxWeight;
}