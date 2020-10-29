// N 과 M(6) 조합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool selected[8]={false};
void combination(int target, int index, vector<int> realNumVector,vector<int> numVector){
    if(target == 0){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = index; i < realNumVector.size(); i++){
        if(selected[i]) continue;
        numVector.push_back(realNumVector[i]);
        selected[i] = true;
        combination(target - 1, i, realNumVector, numVector);
        selected[i] = false;
        numVector.pop_back();
    }
}
int main(void){
    int count, target, num;
    cin >> count >> target;
    vector<int> realNumVector, numVector;
    for(int i = 0; i < count ; i++){
        cin >> num;
        realNumVector.push_back(num);
    }
    sort(realNumVector.begin(), realNumVector.end());
    combination(target, 0, realNumVector, numVector);
}