// 오르막수
#include <iostream>
using namespace std;

int main(void){
    int count, total = 0,dp[1001][10] = {0};
    cin >> count;
    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= count; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k < 10; k++){
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        total = (total + dp[count][i]) % 10007;
    }
    cout << total;
}