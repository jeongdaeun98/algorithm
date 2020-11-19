//거꾸로 구구단
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    vector<string> reverseVector;
    for(int i = 1; i <= b; i++){
        int num = a * i;
        string reverseNum = to_string(num);
        reverse(reverseNum.begin(), reverseNum.end());
        reverseVector.push_back(reverseNum);
    }
    int maxNum = 0;
    for(int i = 0; i < reverseVector.size(); i++){
        maxNum = max(maxNum, stoi(reverseVector[i]));
    }
    cout << maxNum;
}