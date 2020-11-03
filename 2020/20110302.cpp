// 연속합(2)
#include <iostream>
using namespace std;

int main(void){
    int n, arr[100001], dp[100001][2], answer;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    answer = dp[0][0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(arr[i] + dp[i - 1][0], arr[i]);
        dp[i][1] = max(arr[i] + dp[i - 1][1], dp[i - 1][0]);
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    cout << answer;
}