// 부분수열의 합
#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
bool selected[21] = {false};
void combination(int target, int index, int sum, int size, vector<int> realVector){
    if(size == 0){
        if(sum == target){
            answer ++;
        }
        return;
    }
    for(int i = index; i < realVector.size(); i++){
        if(selected[i]) continue;
        selected[i] = true;
        combination(target, i, sum + realVector[i], size - 1, realVector);
        selected[i] = false;
    }
}
int main(void){
    int count, target, num;
    cin >> count >> target;
    vector<int> realVector;
    for(int i = 0; i < count; i++){
        cin >> num;
        realVector.push_back(num);
    }
    for(int i = 1; i <= count; i++){
        combination(target, 0, 0, i, realVector);
    }
    cout << answer;
}