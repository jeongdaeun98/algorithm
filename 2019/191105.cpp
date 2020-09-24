#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n,triangle[501][501],maxnum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) 
			cin >> triangle[i][j];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
			else if (j == 0) triangle[i][j] += triangle[i - 1][j];
			else triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (maxnum < triangle[n - 1][i])
			maxnum = triangle[n - 1][i];
	}
	cout << maxnum;
}