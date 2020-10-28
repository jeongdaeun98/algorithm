#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numVector;
vector<vector<int>> permutationVector;
void swap(int a, int b){
    int temp = numVector[a];
    numVector[a] = numVector[b];
    numVector[b] = temp;
}
void permutation(int size, int index){
    if(index == size - 1){
        permutationVector.push_back(numVector);
    }
    else{
        for(int i = index; i < size; i++){
            swap(i, index);
            permutation(size, index + 1);
            swap(i, index);
        }
    }
}
int main(void){
    int count;
    cin >> count;
    for(int i = 0; i < count; i++){
        numVector.push_back(i + 1);
    }
    permutation(count, 0);
    sort(permutationVector.begin(), permutationVector.end());
    for(int i = 0; i < permutationVector.size(); i++){
        for(int j = 0; j < count; j++){
            cout << permutationVector[i][j] << " ";
        }
        cout << "\n";
    }
}