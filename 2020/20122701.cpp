//치킨 배달
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int house[50][50];
int minNum = 987654321;
vector<pair<int,int>> houseVector;
void dfs(int target,int index, vector<pair<int,int>> realVector, vector<pair<int,int>> chickenVector){
    if(index > realVector.size()) return;
    if(target == 0){
        int houseWeight = 0;
        for(int i = 0; i < houseVector.size(); i++){
            int weight = 52;
            for(int j = 0; j < chickenVector.size(); j++){
                weight = min(weight, abs(houseVector[i].first - chickenVector[j].first) + abs(houseVector[i].second - chickenVector[j].second));
            }
            houseWeight += weight;
        }
        minNum = min(houseWeight, minNum);
        return;
    }
        chickenVector.push_back({realVector[index].first,realVector[index].second});
        dfs(target - 1, index + 1, realVector, chickenVector);
        chickenVector.pop_back();
        dfs(target, index + 1, realVector, chickenVector);
}
int main(void){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> chickenVector;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> house[i][j];
            if(house[i][j] == 2){
                chickenVector.push_back({i,j});
            }
            if(house[i][j] == 1){
                houseVector.push_back({i,j});
            }
        }
    }
    vector<pair<int,int>> cVector;
    dfs(m, 0, chickenVector, cVector);
    cout << minNum;
}