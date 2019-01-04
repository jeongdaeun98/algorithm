#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int n, sumtime = 0;
	cin >> n;
	int *p = new int[n];
	int *time = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		if (i != 0)
			time[i] = p[i] + time[i - 1];
		else
			time[i] = p[i];
		sumtime = sumtime + time[i];
	}

	cout << sumtime;


}