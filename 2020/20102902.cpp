//백준 N과 M (10)
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int selected[8] = {false};
void combination(int target, int index, vector<int> realNumVector, vector<int> numVector){
    if(target == 0){
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i] << " ";
        }
        cout << "\n";
        return;
    }
    int beforeNum = -1;
    for(int i = index; i < realNumVector.size(); i++){
        if(selected[i] || beforeNum == realNumVector[i]) continue;
        selected[i] = true;
        beforeNum = realNumVector[i];
        numVector.push_back(realNumVector[i]);
        combination(target - 1, i, realNumVector, numVector);
        numVector.pop_back();
        selected[i] = false;
    }
}
int main(void){
    int count, target, num;
    cin >> count >> target;
    vector<int> realNumVector, numVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realNumVector.push_back(num);
    }
    sort(realNumVector.begin(), realNumVector.end());
    combination(target, 0, realNumVector, numVector);
}