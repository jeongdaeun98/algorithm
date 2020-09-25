#include <iostream>
#include <queue>
using namespace std;

int weight[100001];
int directX[] = {1, -1, 2};
int soobin, sister;
void bfs(){
    queue<int> q;
    cin >> soobin >> sister;
    for(int i = 0; i <= 100000; i++){
        weight[i] = 0;
    }
    q.push(soobin);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            int dx;
            if(i == 0 || i == 1){
                dx = node + directX[i];
            }
            else{
                dx = node * directX[i];
            }
            if(dx >= 0 && dx <= 100000 && weight[dx] == 0 && dx != soobin){
                q.push(dx);
                weight[dx] = weight[node] + 1;
            }
        }
    }
}
int main(void){
    bfs();
    cout << weight[sister];
}