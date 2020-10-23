#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int>> world[1001];
int m,n,endPoint;
void initWorld(){
    cin >> m >> n >> endPoint;
    for(int i = 0; i < n; i++){
        int x,y,weight;
        cin >> x >> y >> weight;
        world[x].push_back(make_pair(weight, y));
    }
}

int dijkstra(int start, int end){
    vector<int> minWeight(m + 1);
    for(int i = 0; i <= m; i++){
        minWeight[i] = 987654321;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < world[node.second].size(); i++){
            int x = world[node.second][i].second;
            int weight = world[node.second][i].first + node.first;
            if( weight < minWeight[x]){
                minWeight[x] = weight;
                pq.push(make_pair(weight, x));
            }
        }
    }
    return minWeight[end];
}
int main(void){
    initWorld();
    int maxWeight = 0;
    for(int i = 1; i <= m; i++){
        if(i == endPoint) continue;
        int num = dijkstra(endPoint,i) + dijkstra(i,endPoint);
        if(maxWeight < num)
            maxWeight = num;
    }
    cout << maxWeight;
}