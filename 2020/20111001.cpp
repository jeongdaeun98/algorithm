//단어 수학
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

string alphaNum[11];
int n, number = 9, answer = 0;
int alpha['Z' - 'A' + 1] = {0,};
map<char,long long> alphaMap;
string str[11];
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return alphaMap[str[a.second][a.first - 1]] < alphaMap[str[b.second][b.first - 1]];
        }
        return a.first < b.first;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> alphaStrCountPq;
int main(void){
    fill_n(alphaNum, 11, "");
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str[i];
        reverse(str[i].begin(), str[i].end());
        for(int j = 0; j < str[i].size(); j++){
            alphaMap[str[i][j]] += (int)pow(10, j);
        }
    }
    for(int i = 0; i < n; i++){
        alphaStrCountPq.push({str[i].size(), i});
    }
    while(!alphaStrCountPq.empty()){
        pair<int,int> alphaStrCount = alphaStrCountPq.top();
        alphaStrCountPq.pop();
        int idx = alphaStrCount.first - 1;
        int strIdx = alphaStrCount.second;
        if(alpha[str[strIdx][idx] - 'A'] != 0){
            alphaNum[strIdx] += alpha[str[strIdx][idx] - 'A'] + '0';
        }
        else{
            alphaNum[strIdx] += number + '0';
            alpha[str[strIdx][idx] - 'A'] = number;
            number--;
        }
        if(idx != 0){
            alphaStrCountPq.push({idx, strIdx});
        }
    }
    for(int i = 0; i < n; i++){
        cout << alphaNum[i] << "\n";
        answer += stoi(alphaNum[i]);
    }
    cout << answer;

}

/*
2
ABCDEFGH
IJAABBCC

6
ABABABAB
BABABABA
ABABABAB
BABABABA
CCCCCCCA
CCCCCCBA

4
CCCCCCCA
CCCCCCBA
AAAAAAAC
AAAAAABC

*/