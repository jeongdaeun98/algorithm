#include <iostream>
using namespace std;

bool **checked;
int **vertex;
void initVertex(int m, int n){
    vertex = new int*[m];
    for(int i = 0; i < m; i++){
        vertex[i] = new int[n];
    }
}
void initChecked(int m, int n){
    checked = new bool*[m];
    for(int i = 0 ; i < m; i++){
        checked[i] = new bool[n];
        for(int j = 0; j < n; j++){
            checked[i][j] = false;
        }
    }
}
void dfs(int x, int y, int m, int n){
    checked[x][y] = true;
    int directX[] = {0,0,1,-1};
    int directY[] = {1,-1, 0, 0};
    for(int i = 0; i < 4; i++){
        int dx = directX[i] + x;
        int dy = directY[i] + y;
        if(dx < m && dx >= 0 && dy < n && dy >= 0 && !checked[dx][dy] && vertex[dx][dy] == 1){
            dfs(dx,dy, m, n);
        }
    }
}
int searchDfs(int m , int n){
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!checked[i][j] && vertex[i][j] == 1){
                count++;
                dfs(i, j, m, n);
            }
        }
    }
    return count;
}
int main(void){
    int testCase, m, n, k;
    cin >> testCase;

    for(int i = 0 ; i < testCase; i++){
        cin >> m >> n >> k;
        initVertex(m, n);
        initChecked(m, n);
        for(int j = 0; j < k; j++){
            int a,b;
            cin >> a >> b;
            vertex[a][b] = 1;
        }
        cout << searchDfs(m, n) << "\n";
    }
}