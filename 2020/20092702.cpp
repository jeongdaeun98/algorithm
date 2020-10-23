#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int>> bus[1001];
int minWeight[1001];
int n,m,start,endVertex;
void initBus(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,weight;
        cin >> a >> b >> weight;
        bus[a].push_back(make_pair(weight, b));
    }
    cin >> start >> endVertex;
}
void dijkstra(){
    for(int i = 1; i <= n; i++){
        minWeight[i] = 987654321;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,start));
    minWeight[start] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < bus[node.second].size(); i++){
            int x = bus[node.second][i].second;
            if(bus[node.second][i].first + node.first < minWeight[x]){
                minWeight[x] = bus[node.second][i].first + node.first;
                pq.push(make_pair(minWeight[x],x));
            }
        }
    }
}

int main(void){
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    initBus();
    dijkstra();
    cout << minWeight[endVertex];
}