#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, glass[10001], dp[10001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> glass[i];
	dp[1] = glass[1];
	if(n > 1)
		dp[2] = glass[1] + glass[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1],max(glass[i] + dp[i - 2], glass[i] + glass[i - 1] + dp[i - 3]));
	}
	cout << dp[n];
}