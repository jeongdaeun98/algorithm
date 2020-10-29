//백준 N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool selected[9] = {false};
void permutationAndCombination(int target, int index, vector<int> realNumVector, vector<int> numVector){
    if(target == index){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < realNumVector.size(); i++){
        if(selected[i]) continue;
        selected[i] = true;
        numVector.push_back(realNumVector[i]);
        permutationAndCombination(target, index + 1, realNumVector, numVector);
        numVector.pop_back();
        selected[i] = false;
    }
}
int main(void){
    int count, target, num;
    cin >> count >> target;
    vector<int> realNumVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realNumVector.push_back(num);
    }
    sort(realNumVector.begin(), realNumVector.end());
    vector<int> numVector;
    permutationAndCombination(target, 0, realNumVector, numVector);
}