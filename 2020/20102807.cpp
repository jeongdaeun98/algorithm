#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void overlapCombination(int target, int index, vector<int> realVector, vector<int> numVector){
    if(target == 0){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(index == realVector.size()){
        return;
    }
        numVector.push_back(realVector[index]);
        overlapCombination(target - 1, index, realVector, numVector);
        numVector.pop_back();
        overlapCombination(target, index + 1, realVector, numVector);
}
int main(void){
    int count,target, num;
    cin >> count >> target;
    vector<int> realVector, numVector;
    for(int i = 0; i < count ; i++){
        cin >> num;
        realVector.push_back(num);
    }
    sort(realVector.begin(), realVector.end());
    overlapCombination(target, 0, realVector, numVector);
}