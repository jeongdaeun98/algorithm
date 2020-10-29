//백준 N과 M (9)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool selected[9] = {false};
void permutation(int index, int target, vector<int> realNumberVector, vector<int> numVector){
    if(index == target){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    int beforeNum = -1;
    for(int i = 0; i < realNumberVector.size(); i++){
        if(!selected[i] && beforeNum != realNumberVector[i]){
            beforeNum = realNumberVector[i];
            selected[i] = true;
            numVector.push_back(realNumberVector[i]);
            permutation(index + 1, target, realNumberVector, numVector);
            numVector.pop_back();
            selected[i] = false;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count, target, num;
    cin >> count >> target;
    vector<int> realNumberVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realNumberVector.push_back(num);
    }
    vector<int> numVector;
    sort(realNumberVector.begin(), realNumberVector.end());
    permutation(0, target, realNumberVector, numVector);
}