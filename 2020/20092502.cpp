#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int tomato[100][100][100];
int weight[100][100][100];
int n,m,h, maxWeight = 0;
int directX[] = {0,0,1,-1};
int directY[] = {1,-1,0,0};
int directZ[] = {1, -1};
queue<tuple<int,int,int> > q;
tuple <int,int,int> node;
void initTomato(){
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    q.push(make_tuple(k,j,i));
                }
            }
        }
    }
}
void initWeight(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                weight[i][j][k] = 0;
            }
        }
    }
}
void bfsLogic(int dx, int dy, int dz){
    if(dx >= 0 && dy >= 0 && dz >= 0 && dx < m && dy < n && dz < h && tomato[dz][dy][dx] == 0 && !weight[dz][dy][dx]){
        weight[dz][dy][dx] += weight[get<2>(node)][get<1>(node)][get<0>(node)] + 1;
        tomato[dz][dy][dx] = 2;
        q.push(make_tuple(dx,dy,dz));
        if(maxWeight < weight[dz][dy][dx]) maxWeight = weight[dz][dy][dx];
    }
}
void bfs(){
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            bfsLogic(directX[i] + get<0>(node), directY[i] + get<1>(node), get<2>(node));
        }
        for(int i = 0; i < 2; i++){
            bfsLogic(get<0>(node), get<1>(node), directZ[i] + get<2>(node));
        }
    }
}

int main(void){
    initTomato();
    initWeight();
    bfs();
    bool ripeTrue = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(tomato[i][j][k] == 0){
                    ripeTrue = false;
                    break;
                }
            }
            if(!ripeTrue) break;
        }
        if(!ripeTrue) break;
    }
    if(!ripeTrue) cout << -1;
    else cout << maxWeight;
}