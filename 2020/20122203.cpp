//연산자 끼워넣기
#include <vector>
#include <iostream>
using namespace std;

int num[12];
int maxNum = -9876543210;
int minNum = 9876543210;
void permutation(int index, int size, int plusCount, int minusCount, int multipleCount, int divideCount, int sum){
   if(index == size){
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }
        if(plusCount != 0) permutation(index + 1, size, plusCount - 1,minusCount, multipleCount, divideCount, sum + num[index + 1]);
        if(minusCount != 0) permutation(index + 1, size, plusCount,minusCount - 1, multipleCount, divideCount, sum - num[index + 1]);
        if(multipleCount != 0) permutation(index + 1, size, plusCount,minusCount, multipleCount - 1, divideCount, sum * num[index + 1]);
        if(divideCount != 0) permutation(index + 1, size, plusCount,minusCount, multipleCount, divideCount - 1, sum / num[index + 1]);
}
int main(void){
    int numSize,plus,minus,multiple,divide;
    vector<int> realVector;
    cin >> numSize;
    for(int i = 0; i < numSize; i++){
        cin >> num[i];
    }
    cin >> plus >> minus >> multiple >> divide;
    permutation(0, numSize - 1,plus, minus, multiple, divide,num[0]);
    cout << maxNum << "\n" << minNum;
}