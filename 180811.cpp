#include <iostream>
using namespace std;
int main(void) {

	int num[9],pivot;
	int sum = 0, i,j;
	for ( i = 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sum -= 100;
	for (i = 0; i < 9; i++) {
		for (j = i+1; j < 9; j++)
			if (num[i] + num[j] == sum) { num[i] = -1; num[j] = 0; break; }
		if (num[i] == -1) break;
	}

	for (i = 1; i < 9; i++) {
		pivot = num[i];
		for (j = i - 1; j >= 0 && pivot < num[j]; j--)
			num[j + 1] = num[j];
		num[j + 1] = pivot;
	}
	for (i = 2; i < 9; i++) {

			cout << num[i];
			cout << "\n";
	}
}