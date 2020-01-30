#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int stair[300], d[300], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];
	d[0] = stair[0];
	d[1] = max(stair[0] + stair[1], stair[1]);
	d[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
 	for (int i = 3; i < n; i++)
		d[i] = max(stair[i - 1] + stair[i] + d[i - 3], d[i - 2] + stair[i]);
	
	cout << d[n - 1];
}