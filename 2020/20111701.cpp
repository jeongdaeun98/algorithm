//숨바꼭질 2
#include <iostream>
#include <queue>
using namespace std;
bool visited[100001];
int minCount = 0, minWeight = 0;
void bfs(int n, int k){
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n] = true;
    while(!q.empty()){
        pair<int,int> node = q.front();
        int point = node.first;
        int weight = node.second;
        q.pop();
        if(point == k && !visited[point]){
            minWeight = weight;
            minCount++;
        }
        if(point == k && visited[point] && weight == minWeight){
            minCount++;
        }
        visited[point] = true;
        if(point * 2 >= 0 && point * 2 <= 100000 && !visited[point * 2]){
            q.push({point*2,weight+1});
        }
        if(point - 1 >= 0 && point - 1 <= 100000 && !visited[point - 1]){
            q.push({point - 1, weight+1});
        }
        if(point + 1 >= 0 && point + 1 <= 100000 && !visited[point + 1]){
            q.push({point + 1, weight +1});
        }
    }
}
int main(void){
    int n,k;
    cin >> n >> k;
    fill_n(visited, 100001, false);
    bfs(n,k);
    cout << minWeight << "\n" << minCount;
}