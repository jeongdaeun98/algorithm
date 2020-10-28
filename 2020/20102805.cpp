#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> combinationVector;
void combination(int target, int index, vector<int> realVector, vector<int> numVector){
    if(target == 0){
        sort(numVector.begin(), numVector.end());
        combinationVector.push_back(numVector);
        return;
    }
    if(index == realVector.size()){
        return;
    }
    numVector.push_back(realVector[index]);
    combination(target - 1, index + 1, realVector, numVector);
    numVector.pop_back();
    combination(target, index + 1, realVector, numVector);
}
int main(void){
    int count, target, num;
    vector<int> realVector;
    cin >> count >> target;
    for(int i = 0; i < count; i++){
        cin >> num;
        realVector.push_back(num);
    }
    vector<int> numVector;
    combination(target, 0, realVector, numVector);
    sort(combinationVector.begin(), combinationVector.end());
    for(int i = 0; i < combinationVector.size(); i++){
        for(int j = 0; j < combinationVector[i].size(); j++){
            cout << combinationVector[i][j] << " ";
        }
        cout << "\n";
    }
}