#include<iostream>
#include<queue>
#include<stack>
using namespace std;

vector<int> dfsVisitedVector;
vector<int> bfsVisitedVector;
int vertex[1001][1001];
bool visitedArray[1001] = {false, };
void init(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visitedArray[i] = false;
        }
    }
}
void dfs(int v, int n){
    stack<int> stack;
    stack.push(v - 1);
    visitedArray[v - 1] = true;
    dfsVisitedVector.push_back(v);
    while(!stack.empty()){
        int node = stack.top();
        stack.pop();
        for(int i = 0; i < n; i++){
            if(vertex[node][i] == 1 && !visitedArray[i]){
                stack.push(node);
                stack.push(i);
                dfsVisitedVector.push_back(i + 1);
                visitedArray[i] = true;
                break;
            }
        }
    }
}
void bfs(int v, int n){
    queue<int> q;
    q.push(v - 1);
    bfsVisitedVector.push_back(v);
    visitedArray[v - 1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(vertex[node][i] == 1 && !visitedArray[i]){
                q.push(i);
                bfsVisitedVector.push_back(i + 1);
                visitedArray[i] = true;
            }
        }
    }
}
int main(void){
    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        vertex[x - 1][y - 1] = 1;
        vertex[y - 1][x - 1] = 1;
    }
    init(n);
    dfs(v, n);
    init(n);
    bfs(v, n);
    for(int i = 0; i < dfsVisitedVector.size(); i++){
        cout << dfsVisitedVector[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < bfsVisitedVector.size(); i++){
        cout << bfsVisitedVector[i] << " ";
    }
    
}