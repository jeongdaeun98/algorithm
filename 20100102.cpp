#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int a, b, eraseCount = 0;
    cin >> a >> b;
    vector<int> comparedNum(a);
    unordered_map<int,int> compareMap;
    for(int i = 0; i < a; i++){
        cin >> comparedNum[i];
        compareMap.insert(make_pair(comparedNum[i], i));
    }
    for(int i = 0; i < b; i++){
        int comparingNum;
        cin >> comparingNum;
        if(compareMap.find(comparingNum) != compareMap.end()){
            comparedNum[compareMap.find(comparingNum)->second] = -1;
            eraseCount++;
        }
    }
    sort(comparedNum.begin(), comparedNum.end());
    cout << comparedNum.size() - eraseCount << "\n";
    if(comparedNum.size() - eraseCount != 0){
    for(int i = 0; i < comparedNum.size(); i++){
        if(comparedNum[i] != -1){
            cout << comparedNum[i];
            if(i != comparedNum.size() -1){
                cout << " ";
            }
        }
    }
    }
}