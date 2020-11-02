// 스티커
#include <iostream>
using namespace std;

int main(void){
    int test, num,dp[2][100001];
    cin >> test;
    while(test--){
        cin >> num;
        dp[0][0] = 0; dp[1][0] = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= num; j++){
                cin >> dp[i][j];
            }
        }
        for(int i = 2; i <= num; i++){
            dp[0][i] = max(dp[0][i] + dp[1][i - 1],dp[0][i] + dp[1][i - 2]);
            dp[1][i] = max(dp[1][i]+ dp[0][i - 1], dp[1][i] + dp[0][i - 2]);
        }
        cout << max(dp[0][num], dp[1][num]) << "\n";
    }
}