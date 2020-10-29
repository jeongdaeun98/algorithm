// 연산자 끼워넣기
#include <iostream>
#include <vector>
using namespace std;

char operatorArray[] = {'+', '-', '*', '/'};
vector<int> numVector;
bool selected[11] = {false};
long long maxNum = -9876543210;
long long minNum = 9876543210;
void permutation(int index,vector<char> realOperatorVector, vector<char> operatorVector){
    if(index == realOperatorVector.size()){
        long long sum = numVector[0];
        for(int i = 1; i < numVector.size(); i++){
            if(operatorVector[i - 1] == '+'){
                sum += numVector[i];
            }
            else if(operatorVector[i - 1] == '-'){
                sum -= numVector[i];
            }
            else if(operatorVector[i - 1] == '*'){
                sum *= numVector[i];
            }
            else{
                sum /= numVector[i];
            }
        }
        if(maxNum < sum) maxNum = sum;
        if(minNum > sum) minNum = sum;

        return;
    }
    for(int i = 0; i < realOperatorVector.size(); i++){
        if(selected[i]) continue;
        selected[i] = true;
        operatorVector.push_back(realOperatorVector[i]);
        permutation(index + 1, realOperatorVector, operatorVector);
        operatorVector.pop_back();
        selected[i] = false;
    }
}
int main(void){
    int count, num, operatorCount;
    vector<char> realOperatorVector, operatorVector;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> num;
        numVector.push_back(num);
    }
    for(int i = 0; i < 4; i++){
        cin >> operatorCount;
        while(operatorCount--){
            realOperatorVector.push_back(operatorArray[i]);
        }
    }
    permutation(0, realOperatorVector, operatorVector);
    cout << maxNum << "\n" << minNum;
    
}