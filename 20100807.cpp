#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

vector<pair<int,int>> vertex[801];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int weight[3][801];
void initWeight(int v){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= v; j++){
            weight[i][j] = 98761;
        }
    }
}
void initVertex(int v, int e){
    for(int i = 0; i < e; i++){
        int start,end,w;
        cin >> start >> end >> w;
        vertex[start].push_back(make_pair(w, end));
        vertex[end].push_back(make_pair(w, start));
    }
}
void dijkstra(int v, int endOne, int endTwo){
    int a[] = {1, endOne, endTwo };
    for(int j = 0; j < 3; j++){
        weight[j][a[j]] = 0;
        pq.push(make_pair(0,a[j]));
        while(!pq.empty()){
            pair<int,int> node = pq.top();
            pq.pop();
            for(int i = 0; i < vertex[node.second].size(); i++){
                if(weight[j][vertex[node.second][i].second] > vertex[node.second][i].first + node.first){
                    weight[j][vertex[node.second][i].second] = vertex[node.second][i].first + node.first;
                    pq.push(make_pair(vertex[node.second][i].first + node.first, vertex[node.second][i].second));
                }
            }
        }
    }
}
int main(void){
    int v, e, endOne, endTwo;
    cin >> v >> e;
    initVertex(v, e);
    initWeight(v);
    cin >> endOne >> endTwo;
    int answer = 0;
    dijkstra(v, endOne, endTwo);
    answer = min(weight[0][endOne]+weight[1][endTwo]+weight[2][v], weight[0][endTwo]+weight[2][endOne]+weight[1][v]);
    if(answer >= 98761) cout << -1;
    else cout << answer;
}