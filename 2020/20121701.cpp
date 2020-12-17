//리모컨
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unsigned long answer = 987654321;
void overlapPermutation(vector<int> num, string realNumStr, int target, string numStr){
    if(target == 0){
        answer = min(abs(stoi(realNumStr) - stoi(numStr)) + numStr.length(), answer);
        return;
    }
    for(int i = 0; i < num.size(); i++){
        overlapPermutation(num, realNumStr, target - 1, numStr + to_string(num[i]));
    }
}
int main(void){
    unordered_map<int, bool> removedNumHash;
    int n, removedNum;
    unsigned long channelPassSum;
    string numStr;
    cin >> numStr;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> removedNum;
        removedNumHash.insert({removedNum, true});
    }
    vector<int> numVector;
    for(int i = 0; i < 10; i++){
        if(!removedNumHash.empty()&&removedNumHash.find(i) == removedNumHash.end()){
            numVector.push_back(i);
        }
        if(removedNumHash.empty()){
            numVector.push_back(i);
        }
    }

    if(stoi(numStr) > 100){
        channelPassSum = stoi(numStr) - 100;
    }
    else{
        channelPassSum = 100 - stoi(numStr);
    }
    for(int i = 1; i <= 6; i++){
        overlapPermutation(numVector, numStr, i, "");
    }
    cout << min(channelPassSum, answer);
}