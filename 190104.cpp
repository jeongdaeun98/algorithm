#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num = 0;
	cin >> num;
	int *a = new int[num];
	int *b = new int[num];
	int *sum = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> a[i];
		cin >> b[i];
		sum[i] = a[i] + b[i];
	}
	for (int i = 0; i < num; i++) {
		cout << sum[i];
		cout << '\n';
	}
	
}

