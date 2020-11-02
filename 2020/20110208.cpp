// 가장 긴 증가하는 부분수열 4
#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int count, answer = 1, dp[1001], arr[1001];
    stack<int> stack;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> arr[i];
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
                answer = max(answer, dp[i]);
            }
        }
    }
    cout << answer << "\n"; 
    for(int i = count - 1; i >= 0; i--){
            if(answer == dp[i]){
                stack.push(arr[i]);
                answer--;
            }
    }
    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
}