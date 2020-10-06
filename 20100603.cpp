#include <queue>
#include <vector>

using namespace std;

int weight[101];
int direct[] = {1,2};
void initWeight(int n){
    for(int i = 0; i < n; i++){
        weight[i] = 0;
    }
}
void bfs(int n, vector<int> c){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < 2; i++){
            int dx = node + direct[i];
            if(dx < n && !weight[dx] && c[dx] != 1){
                weight[dx] = weight[node] + 1;
                q.push(dx);
            }
        }
    } 
}
// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    initWeight(c.size());
    bfs(c.size(), c);
    return weight[c.size() - 1];
}