#include <iostream>
#include <queue>
using namespace std;

int g,s,f,u,d;
int weight[1000001];
void bfs(){
    for(int i = 0; i <= f; i++){
        weight[i] = 0;
    }
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < 2; i++){
            int newNode;
            if(i == 0){
                newNode = node + u;
            }
            else{
                newNode = node - d;
            }
            if(newNode > 0 && newNode <= f && !weight[newNode] && newNode != s){
                q.push(newNode);
                weight[newNode] = weight[node] + 1;
            }
        }
    }
}
int main(void){
    cin >> f >> s >> g >> u >> d;
    bfs();
    if(s != g && weight[g] == 0) cout << "use the stairs";
    else cout << weight[g];
}