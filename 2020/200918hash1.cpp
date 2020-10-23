#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesMap;
    for(int i = 0; i < clothes.size(); i++){
        if(clothesMap.find(clothes[i][1]) != clothesMap.end()) {
            int clothNum = clothesMap.find(clothes[i][1])->second;
            clothesMap.erase(clothes[i][1]);
            clothesMap.insert(make_pair(clothes[i][1], clothNum + 1));
        }
        else {
            clothesMap.insert(make_pair(clothes[i][1], 1));
        }
    }
    for(pair<string, int> clothPair : clothesMap) {
        answer *= (clothPair.second + 1);
    }
    return (answer - 1);
}