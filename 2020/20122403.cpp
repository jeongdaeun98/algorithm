//감시
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
pair<int,int> direction[] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
pair<pair<int,int>,pair<int,int>> secondDirection[] = {{{-1,0}, {1,0}},{{0,-1},{0,1}}};
pair<pair<int,int>,pair<int,int>> thirdDirection[] = {{{-1,0},{0,-1}},{{1,0},{0,1}}, {{1,0},{0,-1}}, {{-1,0},{0,1}}};
tuple<pair<int,int>, pair<int,int>, pair<int,int>> fourthDirection[] = {{{-1,0},{0,-1},{1,0}},{{0,-1},{-1,0},{0,1}},{{1,0},{-1,0},{0,1}},{{0,1},{0,-1},{1,0}}};
int n,m, minNum = 987654321;
int matrix[8][8];
vector<int> cctvVector;
vector<pair<int,int>> cctvVertexVector;
void watchCCTV(int dx,int dy, int directx, int directy){
    while(1){
        dx += directx;
        dy += directy;
        if(dx < 0 || dx >= n || dy < 0 || dy >= m || matrix[dx][dy] == 6) break;
        if(matrix[dx][dy] == 0){
            matrix[dx][dy] = 7;
        }
    }
}
void copyMap(int copiedMatrix[8][8]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = copiedMatrix[i][j];
        }
    }
}
void watchForFirstCCTV(int index, int directionIdx){
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,direction[directionIdx].first,direction[directionIdx].second);
}

void watchForSecondCCTV(int index, int directionIdx){
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,secondDirection[directionIdx].first.first,secondDirection[directionIdx].first.second);
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,secondDirection[directionIdx].second.first,secondDirection[directionIdx].second.second);
}
void watchForThirdCCTV(int index, int directionIdx){
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,thirdDirection[directionIdx].first.first,thirdDirection[directionIdx].first.second);
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,thirdDirection[directionIdx].second.first,thirdDirection[directionIdx].second.second);
}
void watchForFourthCCTV(int index, int directionIdx){
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,get<0>(fourthDirection[directionIdx]).first,get<0>(fourthDirection[directionIdx]).second);
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,get<1>(fourthDirection[directionIdx]).first,get<1>(fourthDirection[directionIdx]).second);
    watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,get<2>(fourthDirection[directionIdx]).first,get<2>(fourthDirection[directionIdx]).second);
}
void watchForFifthCCTV(int index){
    for(int i = 0; i < 4; i++){
        watchCCTV(cctvVertexVector[index].first,cctvVertexVector[index].second,direction[i].first, direction[i].second);
    }
}
int getCount(){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                count++;
            }
        }
    }
    return count;
}
void dfs(int index){
    if(index == cctvVector.size()){
        int answer = getCount();
        minNum = min(minNum, answer);
        return;
    }
    int copiedMatrix[8][8];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            copiedMatrix[i][j] = matrix[i][j];
        }
    }
    int cctvNum = cctvVector[index];
    switch(cctvNum){
        case 1:
        for(int i = 0; i < 4; i++){
            watchForFirstCCTV(index, i);
            dfs(index + 1);
            copyMap(copiedMatrix);
        }
        break;
        case 2:
        for(int i = 0; i < 2; i++){
            watchForSecondCCTV(index, i);
            dfs(index + 1);
            copyMap(copiedMatrix);
        }
        break;
        case 3:
        for(int i = 0; i < 4; i++){
            watchForThirdCCTV(index, i);
            dfs(index + 1);
            copyMap(copiedMatrix);
        }
        break;
        case 4:
        for(int i = 0; i < 4; i++){
            watchForFourthCCTV(index, i);
            dfs(index + 1);
            copyMap(copiedMatrix);
        }
        break;
        case 5:
            watchForFifthCCTV(index);
            dfs(index + 1);
        break;
    }
}
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] != 0 && matrix[i][j] != 6){
                cctvVector.push_back(matrix[i][j]);
                cctvVertexVector.push_back({i,j});
            }
        }
    }
    dfs(0);

    cout << minNum;
}