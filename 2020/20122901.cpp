//이차원 배열과 연산
#include <iostream>
#include<string.h>
#include <algorithm>
#include <vector>
using namespace std;
int r, c, k;
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
size_t getColumnCount(vector<vector<int>> a){
    size_t maxNum = 0;
    for(int i = 0; i < a.size(); i++){
        maxNum = max(maxNum, a[i].size());
    }
    return maxNum;
}
vector<int> sortNum(vector<int> a){
    pair<int,int> number[101];
    for(int i = 1; i < 101; i++){
        number[i] = {0,0};
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0) continue;
        number[a[i]] = {number[a[i]].first + 1, a[i]};
    }
    sort(number, number+101, compare);
    vector<int> answer;
    for(int i = 1; i < 101; i++){
        if(number[i].second > 0&& number[i].first > 0 && answer.size() < 100){
            answer.push_back(number[i].second);
            if(answer.size() < 100)
                answer.push_back(number[i].first);
        }
    }
    return answer;
}
bool isBiggerThanColumnCount(vector<vector<int>> a){
    size_t columnCount = getColumnCount(a);
    return columnCount < a.size() || columnCount == a.size();
}
vector<vector<int>> rowToColumn(vector<vector<int>> a, int columnCount){
    vector<vector<int>> answer;
    for(int i = 0; i < columnCount; i++){
        vector<int> columnVector;
        for(int j = 0; j < a.size(); j++){
            columnVector.push_back(a[j][i]);
        }
        answer.push_back(columnVector);
    }
    return answer;
}
void print(vector<vector<int>> numVector){
    cout << "\n";
    for(int i = 0; i < numVector.size(); i++){
        for(int j = 0; j < numVector[i].size(); j++){
            cout << numVector[i][j] << " ";
        }
        cout << "\n";
    }
}
vector<vector<int>> addZero(vector<vector<int>> aVector){
    int maxIndex = getColumnCount(aVector);
            for(int i = 0; i < aVector.size(); i++){
                for(int j = 0; j < maxIndex; j++){
                    if(aVector[i].size() < j || aVector[i].size() == j){
                        aVector[i].push_back(0);
                    }
                }
            }
            return aVector;
}
int main(void){
    cin >> r >> c >> k;
    vector<vector<int>> a;
    for(int i = 0; i < 3; i++){
        vector<int> numVector;
        for(int j = 0; j < 3; j++){
            int num;
            cin >> num;
            numVector.push_back(num);
        }
        a.push_back(numVector);
    }
    int time = 0;
    while(1){
        if(a.size() > r-1 && a[r-1].size() > c-1 && a[r-1][c-1] == k){
            cout << time;
            break;
        }
        if(time == 100){
            cout << -1;
            break;
        }
        time++;
        if(isBiggerThanColumnCount(a)){
            vector<vector<int>> realA;
            for(int i = 0; i < a.size(); i++){
                realA.push_back(sortNum(a[i]));
            }
            a = addZero(realA);
        }
        else{
            size_t columnCount = getColumnCount(a);
            vector<vector<int>> aVector;
            for(int i = 0; i < columnCount; i++){
                vector<int> columnVector;
                for(int j = 0; j < a.size(); j++){
                    columnVector.push_back(a[j][i]);
                }
                columnVector = sortNum(columnVector);
                aVector.push_back(columnVector);
            }
            aVector = addZero(aVector);
            a = rowToColumn(aVector, getColumnCount(aVector));
            a = addZero(a);
        }
    }
}