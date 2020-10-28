#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

bool visited[100001] = {false};
int directx[] = {2, 1, -1};
int dijkstra(int soobin, int sister){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, soobin});
    visited[soobin] = true;

    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        if(node.second == sister){
            return node.first;
        }
         for(int i = 0; i < 3; i++){
            int dx, thisWeight;
            if(i != 0) {
                dx = node.second + directx[i];
                thisWeight = node.first + 1;
            }
            else{ 
                dx = node.second * directx[i];
                thisWeight = node.first;
            }
            if(dx >= 0 && dx <= 100000 && !visited[dx]){
                visited[dx] = true;
                pq.push({thisWeight, dx});
            }
        }
    }
}
int main(void){
    int soobin, sister;
    cin >> soobin >> sister;
    cout << dijkstra(soobin, sister);
}