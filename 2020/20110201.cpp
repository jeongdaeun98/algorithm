// 카드 구매하기
#include <iostream>
using namespace std;

int main(void){
    int count, num;
    cin >> count;
    int p[10001], dp[10001] = {0};
    for(int i = 1; i <= count; i++){
        cin >> num;
        p[i] = num;
    }
    for(int i = 1; i <= count; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }
    cout << dp[count];
}