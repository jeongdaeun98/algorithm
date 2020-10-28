#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permutationVector;
vector<int> swap(int a, int b, vector<int> numVector){
    int temp = numVector[a];
    numVector[a] = numVector[b];
    numVector[b] = temp;
    return numVector;
}
void permutation(int index, vector<int> numVector){
    if(numVector.size() - 1 == index){
        permutationVector.push_back(numVector);
        return;
    }
    for(int i = index; i < numVector.size(); i++){
        numVector = swap(i, index, numVector);
        permutation(index + 1, numVector);
        numVector = swap(i, index, numVector);
    }
}
void combination(int target, int index, vector<int> numVector, vector<int> realNumVector){
    if(target == 0){
        permutation(0, numVector);
        return;
    }
    if(realNumVector.size() == index){
        return;
    }
    numVector.push_back(realNumVector[index]);
    combination(target - 1, index + 1, numVector, realNumVector);
    numVector.pop_back();
    combination(target, index + 1,numVector, realNumVector);
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
    vector<int> numVector;
    combination(target, 0, numVector, realNumVector);
    sort(permutationVector.begin(), permutationVector.end());
    for(int i = 0; i < permutationVector.size(); i++){
        for(int j = 0; j < permutationVector[i].size(); j++){
            cout << permutationVector[i][j] << " ";
        }
        cout << "\n";
    }
}