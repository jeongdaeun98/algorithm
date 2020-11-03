// 합분해
#include <iostream>
using namespace std;

int main(void){
    int n,k,dp[201][201] = {1};
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int l = 0; l <= i; l++){
                dp[i][j] = (dp[i][j] + dp[i - l][j - 1]) % 1000000000;
            }
        }
    }
    cout << dp[n][k] % 1000000000;
}