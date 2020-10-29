//백준 이모티콘
#include <iostream>
#include <queue>
using namespace std;

int weight[1001][1001];
bool visited[1001][1001];
int answer = 0;
void initWeight(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            weight[i][j] = 0;
        }
    }
}
void initVisited(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            visited[i][j] = false;
        }
    }
}
void bfs(int s){
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        if(node.first == s){
            answer = weight[node.first][node.second];
            return;
        }
        if(!visited[node.first][node.first]){
            weight[node.first][node.first] = weight[node.first][node.second] + 1;
            visited[node.first][node.first] = true;
            q.push({node.first, node.first});
        }
        int imojiNumAfterPaste = node.second + node.first;
        if(imojiNumAfterPaste <= 1000 && !visited[imojiNumAfterPaste][node.second]){
            weight[imojiNumAfterPaste][node.second] = weight[node.first][node.second] + 1;
            visited[imojiNumAfterPaste][node.second] = true;
            q.push({imojiNumAfterPaste, node.second});
        }
        int imojiNumAfterAbandon = node.first - 1;
        if(imojiNumAfterAbandon >= 2 && !visited[imojiNumAfterAbandon][node.second]){
            weight[imojiNumAfterAbandon][node.second] = weight[node.first][node.second] + 1;
            visited[imojiNumAfterAbandon][node.second] = true;
            q.push({imojiNumAfterAbandon, node.second});
        }
    }
}
int main(void){
    int s;
    cin >> s;
    bfs(s);
    cout << answer;
}