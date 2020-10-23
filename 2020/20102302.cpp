#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
using namespace std;

int directx[] = {0,0,1,-1};
int directy[] = {1,-1,0,0};
int weight[101][101];
int vertex[101][101];
void initVertex(int n, int m){
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            vertex[i][j] = str[j] - '0';
        }
    }
}
void initWeight(int n, int m){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            weight[i][j] = 987654321;
        }
    }
}
void dijkstra(int n, int m){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push({0,0,0});
    while(!pq.empty()){
        tuple<int,int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int dy = get<1>(node) + directy[i];
            int dx = get<2>(node) + directx[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && vertex[get<1>(node)][get<2>(node)] + get<0>(node) < weight[dy][dx]){
                weight[dy][dx] = vertex[get<1>(node)][get<2>(node)] + get<0>(node);
                pq.push({weight[dy][dx], dy, dx});
            }
        }
    }
}
int main(void){
    int n,m;
    cin >> n >> m;
    initWeight(n , m);
    initVertex(n,m);
    dijkstra(n, m);
    if(n == 1 && m == 1) cout << 0;
    else cout << weight[m - 1][n - 1];
}