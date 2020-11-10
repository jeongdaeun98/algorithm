//부분 수열의 합
#include <iostream>
#include <vector>
using namespace std;

vector<int> numVector;
int sumArr[2000001] = {0,};
void dfs(int target, int index, int sum){
    if(target == index){
        sumArr[sum] = 1;
        return;
    }
    dfs(target, index + 1, sum + numVector[index]);
    dfs(target, index + 1, sum);
}
int main(void){
    int count, num;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> num;
        numVector.push_back(num);
    }
    for(int i = 1; i <= count; i++){
        dfs(i, 0, 0);
    }
    for(int i = 0; i < 2000001; i++){
        if(sumArr[i] == 0){
            cout << i;
            break;
        }
    }
}