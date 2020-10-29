// 연산자 끼워넣기(2)
#include <iostream>
#include <vector>
using namespace std;

vector<int> numVector;
bool selected[11] = {false};
long long maxNum = -9876543210;
long long minNum = 9876543210;
void permutation(int index, int size, int plusCount, int minusCount, int multipleCount, int divideCount, long long sum){
   if(index == size){
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }
        if(plusCount != 0) permutation(index + 1, size, plusCount - 1,minusCount, multipleCount, divideCount, sum + numVector[index + 1]);
        if(minusCount != 0) permutation(index + 1, size, plusCount,minusCount - 1, multipleCount, divideCount, sum - numVector[index + 1]);
        if(multipleCount != 0) permutation(index + 1, size, plusCount,minusCount, multipleCount - 1, divideCount, sum * numVector[index + 1]);
        if(divideCount != 0) permutation(index + 1, size, plusCount,minusCount, multipleCount, divideCount - 1, sum / numVector[index + 1]);
}
int main(void){
    vector<int> operatorVector;
    int count, num;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> num;
        numVector.push_back(num);
    }
    for(int i = 0; i < 4; i++){
        cin >> num;
        operatorVector.push_back(num);
    }
    permutation(0,count - 1,operatorVector[0],operatorVector[1],operatorVector[2],operatorVector[3], numVector[0]);
    cout << maxNum << "\n" << minNum;
    
}