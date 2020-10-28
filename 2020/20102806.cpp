#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void overlapPermutation(int index, vector<int> numVector, vector<int> realVector, int target){
    if(target == index){
        for(int i = 0 ; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < realVector.size(); i++){
        numVector.push_back(realVector[i]);
        overlapPermutation(index + 1, numVector, realVector, target);
        numVector.pop_back();
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count, target, num;
    cin >> count >> target;
    vector<int> realNumVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realNumVector.push_back(num);
    }
    sort(realNumVector.begin(), realNumVector.end());
    vector<int> numVector;
    overlapPermutation(0,numVector, realNumVector, target);
}