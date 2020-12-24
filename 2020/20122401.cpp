//연구소
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

bool visited[8][8];
int area[8][8];
int directx[]= {0,0,1,-1};
int directy[] = {1,-1,0,0};
int maxNum = 0, n, m;
vector<int> safetyAreaVector;
void initVisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }
}
void bfs(){
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(area[i][j] == 2){
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = node.first + directx[i];
            int dy = node.second + directy[i];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && visited[dx][dy] == false && area[dx][dy] == 0){
                area[dx][dy] = 3;
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
}
void combination(int depth){
    if(depth == 3){
        bfs();
        initVisited();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(area[i][j] == 0){
                    count++;
                }
                if(area[i][j] == 3){
                    area[i][j] = 0;
                }
            }
        }
        maxNum = max(maxNum, count);
        return;
    }
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 0) {
				area[i][j] = 1;
				combination(depth + 1);
				area[i][j] = 0;
			}
		}
	}
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> area[i][j];
        }
    }
    combination(0);
    cout << maxNum;
}