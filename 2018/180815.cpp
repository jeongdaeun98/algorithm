#include <iostream>

using namespace std;

int main(void) {

	int num, numcount;
	cin >> num;
	char c[4][3] = {"00","01","10","11"};
	int **count = new int*[num];
	for (int i = 0; i < num; i++) {
		count[i] = new int[4];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> count[i][j];
		}
	}

}