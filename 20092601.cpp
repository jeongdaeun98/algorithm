#include <iostream>
#include <queue>
using namespace std;
int v,e,k;
vector<pair<int,int> > vertex[20010];
int minWeight[20010];
void initVertex(){
    for(int i = 0; i < e; i++){
    int n,m,weight;
    cin >> n >> m >> weight;
    vertex[n].push_back(make_pair(weight, m));
    }

}
void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for(int i = 0; i <= v; i++){
        minWeight[i] = 9999999;
    }
    pq.push(make_pair(0,k));
    minWeight[k] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(int i = 0; i < vertex[node.second].size(); i++){
            int x = vertex[node.second][i].second;
            int newWeight = node.first + vertex[node.second][i].first;
            if(minWeight[x] > newWeight){
                minWeight[x] = newWeight;
                pq.push(make_pair(newWeight,x));
            }
        }
    }
    for(int i = 1; i <= v; i++){
        if(minWeight[i] != 9999999){
            cout << minWeight[i] << "\n";
        }
        else {
            cout << "INF\n";
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e >> k;
    initVertex();
    dijkstra();
}