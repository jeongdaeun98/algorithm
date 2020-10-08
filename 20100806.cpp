#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> vertex[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int weight[20001];
void initWeight(int v){
    for(int i = 0; i <= v; i++){
        weight[i] = 987654321;
    }
}
void initVertex(int v, int e){
    for(int i = 0; i < e; i++){
        int start,end,w;
        cin >> start >> end >> w;
        vertex[start].push_back(make_pair(w, end));
    }
}
void dijkstra(int k, int v){
    pq.push(make_pair(0,k));
    weight[k] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < vertex[node.second].size(); i++){
            if(weight[vertex[node.second][i].second] > vertex[node.second][i].first + node.first){
                weight[vertex[node.second][i].second] = vertex[node.second][i].first + node.first;
                pq.push(make_pair(vertex[node.second][i].first + node.first, vertex[node.second][i].second));
            }
        }
    }
}
int main(void){
    int v, e, k;
    cin >> v >> e >> k;
    initVertex(v, e);
    initWeight(v);
    dijkstra(k, v);
    for(int i = 1; i <= v; i++){
        if(weight[i] == 987654321){
            cout << "INF" << "\n";
        }
        else{
            cout << weight[i] << "\n";
        }
    }
}