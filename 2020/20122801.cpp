//아기 상어
#include <iostream>
#include <queue>
using namespace std;

int water[40][40];
int n;
pair<int,int> babyShark;
int babySharkSize = 2;
pair<int,int> minWeightPoint;
int minWeight;
pair<int,int> direct[] = {{0,1},{0,-1}, {1,0}, {-1,0}};
void bfs(){
    int weight[40][40];
    bool visited[40][40];
    minWeight = 987654321;
    minWeightPoint = {42,42};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            weight[i][j] = 0;
            visited[i][j] = false;
        }
    }
    queue<pair<int,int>> q;
    q.push(babyShark);
    visited[babyShark.first][babyShark.second] = true;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = direct[i].first + node.first;
            int dy = direct[i].second + node.second;
            if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
            if(water[dx][dy] > babySharkSize || visited[dx][dy] == true) continue;
            visited[dx][dy] = true;
            weight[dx][dy] = weight[node.first][node.second] + 1;
            q.push({dx,dy});
            if(water[dx][dy] != 0 && water[dx][dy] < babySharkSize){
                if(minWeight > weight[dx][dy]){
                    minWeight = weight[dx][dy];
                    minWeightPoint = {dx,dy};
                }
                else if(minWeight == weight[dx][dy]){
                    if(dx < minWeightPoint.first){
                        minWeightPoint = {dx,dy};
                    }
                    else if(dx == minWeightPoint.first && dy < minWeightPoint.second){
                        minWeightPoint = {dx,dy};
                    }
                }
            }
        }
    }
}
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> water[i][j];
            if(water[i][j] == 9){
                babyShark = {i,j};
                water[i][j] = 0;
            }
        }
    }
    int answer = 0;
    int eating = 0;
    while(1){
        bfs();
        if(minWeightPoint.first < n && minWeightPoint.second < n){
            answer += minWeight;
            babyShark = minWeightPoint;
            water[babyShark.first][babyShark.second] = 0;
            eating++;
            if(eating == babySharkSize){
                babySharkSize++;
                eating = 0;
            }
        }
        else{
            break;
        }
    }
    cout << answer;
}