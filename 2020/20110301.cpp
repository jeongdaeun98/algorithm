// 연속합
#include <iostream>
using namespace std;

int main(void){
    int n, arr[100001], dp[100001], answer;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    } 
    dp[0] = arr[0];
    answer = arr[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(arr[i], arr[i] + dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    cout << answer;
}