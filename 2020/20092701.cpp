#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int wall[101][101];
int minWeight[101][101];
int directx[] = {0,0,1,-1};
int directy[] = {1,-1,0,0};
int n,m;
void initWall(){
    cin >> m >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            wall[i][j] = str[j] - '0';
        }
    }
}
void dijkstra(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            minWeight[i][j] = 999999;
        }
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push(make_tuple(0,0,0));
    while(!pq.empty()){
        tuple<int, int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int dx = directx[i] + get<1>(node);
            int dy = directy[i] + get<2>(node);
            int weight = get<0>(node) + wall[get<1>(node)][get<2>(node)];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && minWeight[dx][dy] > weight){
                minWeight[dx][dy] = weight;
                pq.push(make_tuple(weight,dx, dy));
            }
        }
    }

}
int main(void){
    initWall();
    dijkstra();
    if(n == 1 && m == 1 && wall[0][0] == 0) cout << 0;
    else cout << minWeight[n-1][m-1];
}