//구슬탈출(2)
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int directx[] = {0, 0, 1, -1};
int directy[] = {1, -1, 0, 0};
bool visited[10][10][10][10];
string vertex[10];
int n, m, answer = -1;
pair<int,int> holl;
struct ball {
    int depth;
    pair<int,int> red, blue;
};
void move(int &x, int &y, int i){
    while(1){
        x += directx[i];
        y += directy[i];
        if(vertex[x][y] == 'O'){
            break;
        }
        if(vertex[x][y] == '#'){
            x -= directx[i];
            y -= directy[i];
            break;
        }
    }
}
void bfs(pair<int,int> pointRed, pair<int, int> pointBlue){
   queue<ball> q;
   q.push({0, pointRed, pointBlue});
   visited[pointRed.first][pointRed.second][pointBlue.first][pointBlue.second] = true;
   while(!q.empty()){
       ball node = q.front();
       q.pop();
        if(node.depth > 10){
            break;
        }
       if(node.red.first == holl.first && node.red.second == holl.second){
            answer = node.depth;
            break;
        }
       for(int i = 0; i < 4; i++){
           int rx = node.red.first;
           int ry = node.red.second;
           int bx = node.blue.first;
           int by = node.blue.second;
           move(rx, ry, i); move(bx, by, i);
           if(bx == holl.first && by == holl.second){
               continue;
           }
           if(rx == bx && ry == by){
               switch(i){
                   case 0:
                   node.red.second > node.blue.second ? by-- : ry--; break;
                   case 1:
                   node.red.second < node.blue.second ? by++ : ry++; break;
                   case 2:
                   node.red.first > node.blue.first ? bx-- : rx--; break;
                   case 3:
                   node.red.first < node.blue.first ? bx++ : rx++; break;
               }
           }
           if(!visited[rx][ry][bx][by]){
               visited[rx][ry][bx][by] = true;
               q.push({node.depth + 1, {rx,ry}, {bx, by}});
           }
       }
   }
}
int main(void){
    cin >> n >> m;
    pair<int,int> pointRed, pointBlue;
    for(int i = 0; i < n; i++){
        cin >> vertex[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(vertex[i][j] == 'R'){
                pointRed = {i,j};
            }
            if(vertex[i][j] == 'B'){
                pointBlue = {i,j};
            }
            if(vertex[i][j] == 'O'){
                holl = {i,j};
            }
        }
    }
    bfs(pointRed, pointBlue);
    cout << answer;
}