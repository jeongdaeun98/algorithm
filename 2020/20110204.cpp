// 쉬운 계단 수
#include <iostream>
using namespace std;
int main(void){
    long long count, dp[101][10], total = 0;
    cin >> count;
    for(int i = 1; i < 10; i++){
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
    for(int i = 2; i <= count; i++){
        for(int j = 0; j < 10; j++){
            if(j == 9){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(j == 0){
                dp[i][j] = dp[i - 1][j + 1];
            }
            else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])% 1000000000;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        total = (total + dp[count][i])% 1000000000;
    }
    cout << total % 1000000000;
}