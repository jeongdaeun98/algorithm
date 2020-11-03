// 제곱수의 합
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(void){
    int n, dp[100001];
    vector<int> multiplyVector;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if((int)sqrt(i) == sqrt(i)){
            dp[i] = 1;
            multiplyVector.push_back(i);
        }
        else{
            dp[i] = 987654321;
            for(int j = 0; j < multiplyVector.size(); j++){
                dp[i] = min(dp[i], dp[multiplyVector[j]] + dp[i - multiplyVector[j]]);
            }
        }
    }
    cout << dp[n];
}