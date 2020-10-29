//백준 N과 M (11)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void overlapCombinationAndPermutation(int target, int index,vector<int> realVector,vector<int> numVector){
    if(target == index){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    int beforeNum = -1;
    for(int i = 0; i < realVector.size(); i++){
        if(beforeNum == realVector[i]) continue;
        beforeNum = realVector[i];
        numVector.push_back(realVector[i]);
        overlapCombinationAndPermutation(target, index + 1, realVector, numVector);
        numVector.pop_back();
    }
}
int main(void){
    int count, target, num;
    cin >> count >> target;
    vector<int> realVector, numVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realVector.push_back(num);
    }
    sort(realVector.begin(), realVector.end());
    overlapCombinationAndPermutation(target, 0, realVector, numVector);
}