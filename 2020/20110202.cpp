// 카드 구매하기(2)
#include <iostream>
using namespace std;
int main(void){
    int count, p[10001], dp[10001];
    cin >> count;
    for(int i = 1; i <= count; i++){
        cin >> p[i];
        dp[i] = 9999999;
    }
    for(int i = 1; i <= count; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i], dp[i - j] + p[j]);
        }
    }
    cout << dp[count];
}