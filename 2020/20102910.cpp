// 좋은 수열
#include <iostream>
#include <vector>
using namespace std;

int numArray[]={1,2,3};
bool isGoodArray = false;
bool isGoodNumArray(vector<int> numVector){
    int length = numVector.size();
    for(int i = 1; i <= length / 2; i++){
        string str1 = "", str2 = "";
        for(int j = 0; j < i; j++){
            str1 += to_string(numVector[length - 2*i + j]);
            str2 += to_string(numVector[length -i + j]);
        }
        if(str1.compare(str2) == 0) return false;
    }
    return true;
}
void dfs(int target, vector<int> numVector){
    if(isGoodArray) return;
    if(target == 0){
        isGoodArray = true;
        for(int i = 0; i < numVector.size(); i++){
            cout << numVector[i];
        }
        return;
    }
    for(int i = 0; i < 3; i++){
        numVector.push_back(numArray[i]);
        if(isGoodNumArray(numVector)){
            dfs(target - 1, numVector);
        }
        numVector.pop_back();
    }
}
int main(void){
    int count;
    cin >> count;
    vector<int> numVector;
    dfs(count, numVector);
}