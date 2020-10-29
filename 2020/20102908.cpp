// 퇴사
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxMoney = 0;
void dfs(int index, int sum, vector<pair<int,int>> moneyVector){
    if(index == moneyVector.size()){
       maxMoney = max(maxMoney, sum);
       return;
    }
    if(index + moneyVector[index].first <= moneyVector.size()){
        dfs(index + moneyVector[index].first, sum + moneyVector[index].second, moneyVector);
    }
    dfs(index + 1, sum, moneyVector);
}
int main(void){
    int count, num, money;
    cin >> count;
    vector<pair<int,int>> moneyVector;
    for(int i = 0; i < count; i++){
        cin >> num >> money;
        moneyVector.push_back({num, money});
    }
    dfs(0, 0, moneyVector);
    cout << maxMoney;
}