//부분 수열의 합2
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<long long,long long> numberMap;
vector<int> numberVector;
long long answer = 0; 
void leftDfs(int target, int index, long long sum){
    if(target == index){
        numberMap[sum]++;
        return;
    }
    leftDfs(target, index + 1, sum + numberVector[index]);
    leftDfs(target, index + 1, sum);
}
void rightDfs(int target, int index, long long sum, int baseNum){
    if(target == index){
        answer += numberMap[baseNum - sum];
        return;
    }
    rightDfs(target, index + 1, sum + numberVector[index], baseNum);
    rightDfs(target, index + 1, sum, baseNum);
}
int main(void){
    int count, baseNum, num;
    cin >> count >> baseNum;
    for(int i = 0; i < count; i++){
        cin >> num;
        numberVector.push_back(num);
    }
    leftDfs(count/2, 0, 0);
    rightDfs(count, count / 2, 0, baseNum);
    if(baseNum == 0) answer--;
    cout << answer;
}