#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> numVector;
int maxSum = 0;
int sumDifference(){
    int sum = 0;
    for(int i = 1; i < numVector.size(); i++){
        sum += abs(numVector[i - 1] - numVector[i]);
    }
    return sum;
}
void swap(int a, int b){
    int temp = numVector[a];
    numVector[a] = numVector[b];
    numVector[b] = temp;
}
void permutation(int size, int index){
    if(size - 1 == index){
        int sum = sumDifference();
        if(maxSum < sum) maxSum = sum;
        return;
    }
    for(int i = index; i < size; i++){
        swap(i, index);
        permutation(size, index + 1);
        swap(i, index);
    }
}
int main(void){
    int count;
    cin >> count;
    for(int i = 0; i < count; i++){
        int num;
        cin >> num;
        numVector.push_back(num);
    }
    permutation(count, 0);
    cout << maxSum;
}