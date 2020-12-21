//퇴사
#include <iostream>
#include <vector>
using namespace std;
int n, maxNum = 0;
vector<pair<int,int>> workVector;
bool isRightDay(int day, int time){
    return day + time <= n + 1;
}
void dfs(int target, int total){
    if(target >= workVector.size()){
        maxNum = max(total, maxNum);
        return;
    }
    if(isRightDay(target + 1, workVector[target].first)){
        dfs(target + workVector[target].first, total + workVector[target].second);
    }
        dfs(target + 1, total);
}
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int day, weight;
        cin >> day >> weight;
        workVector.push_back({day, weight});
    }
    dfs(0, 0);
    cout << maxNum;
}