// 가장 큰 증가 부분수열
#include <iostream>
using namespace std;

int main(void){
    int count, arr[1001], dp[1001], answer;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> arr[i];
    }
    answer = arr[0];
    for(int i = 0; i < count; i++){
        dp[i] = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
                answer = max(answer, dp[i]);
            }
        }
    }
    cout << answer;
}