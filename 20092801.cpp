#include <iostream>
#include <stack>
using namespace std;


int directx[] = {0,0,1,-1,-1,1,1,-1};
int directy[] = {1,-1,0,0,-1,1,-1,1};
int m,n,count = 0;
void dfs(int x, int y,int **island, bool **visited){
    visited[x][y] = true;
    for(int i = 0; i < 8; i++){
        int dx = directx[i] + x;
        int dy = directy[i] + y;
        if(dx >= 0 && dy >= 0 && dx < m && dy < n && island[dx][dy] == 1 && !visited[dx][dy]){
            dfs(dx,dy, island, visited);
        }
    }

}
int searchDfs(int **island, bool **visited){
    int islandCount = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(island[i][j] == 1 && !visited[i][j]){
                dfs(i,j, island, visited);
                islandCount++;
            }
        }
    }
    return islandCount;
}
void initWordAndIslandAndSearch(){
    while(1){
        cin >> n >> m;
        int **island = new int*[m];
        for(int i = 0; i < m; i++){
            island[i] = new int[n];
        }
        bool **visited = new bool*[m];
        for(int j = 0; j < m; j++){
            visited[j] = new bool[n];
        }
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> island[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        cout << searchDfs(island, visited)<< "\n";
    }
}

int main(void){
    initWordAndIslandAndSearch();
}