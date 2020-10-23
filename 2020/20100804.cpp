#include <iostream>
#include <math.h>

using namespace std;

int main(void){
    int dp[1000001];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int num;
    cin >> num;
    for(int i = 4; i <= num; i++){
        int divideThreeNum = 987654321, divideTwoNum = 987654321, minusOneNum = 987654321;
        if(i % 3 == 0){
            divideThreeNum = 1 + dp[i/3];
        }
        if(i % 2 == 0){
            divideTwoNum = 1 + dp[i/2];
        }
        minusOneNum = 1 + dp[i - 1];
        dp[i] = min(divideTwoNum, min(divideThreeNum, minusOneNum));
    }
    cout << dp[num];
}