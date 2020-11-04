//숨바꼭질 4
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int weight[100001] = {0,};
int visited[100001] = {0,};
int trace[100001] = {0,};
void bfs(int n, int k){
    stack<int> stack;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == k){
            cout << weight[k] << "\n";
            int next = k;
            stack.push(k);
            while(trace[next] != n){
                stack.push(trace[next]);
                next = trace[next];
            }
            stack.push(n);
            while(!stack.empty()){
                cout << stack.top() << " ";
                stack.pop();
            }
        }
            int newLocation;
                newLocation = node + 1;
                if(newLocation <= 100000 && newLocation >= 0 && !visited[newLocation]){
                    weight[newLocation] = weight[node] + 1;
                    visited[newLocation] = 1;
                    trace[newLocation] = node;
                    q.push(newLocation);
                }
                newLocation = node - 1;
                if(newLocation <= 100000 && newLocation >= 0 && !visited[newLocation]){
                    weight[newLocation] = weight[node] + 1;
                    visited[newLocation] = 1;
                    trace[newLocation] = node;
                    q.push(newLocation);
                }
                newLocation = node*2;
                if(newLocation <= 100000 && newLocation >= 0 && !visited[newLocation]){
                    weight[newLocation] = weight[node] + 1;
                    visited[newLocation] = 1;
                    trace[newLocation] = node;
                    q.push(newLocation);
                }
    }
}
int main(void){
    int n, k;
    cin >> n >> k;
    if(n == k) cout << 0 << "\n" << n;
    else bfs(n, k);
}