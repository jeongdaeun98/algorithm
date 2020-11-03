// 가장 긴 감소하는 부분 수열
#include <iostream>
using namespace std;

int main(void){
    int count, answer = 1, arr[1001], dp[1001];
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> arr[i];
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
                answer = max(answer, dp[i]);
            }
        }
    }
    cout << answer;
}