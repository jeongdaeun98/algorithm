#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n,num = 1;
	bool zerotrue = false;
	cin >> n;
	while (1) {
		string number = to_string(num);
		int sum = atoi(number.c_str());
		for (int i = 0; i < number.size(); i++) {
			sum += number[i] - '0';
		}
		if (sum == n) { cout << num; break; }
		if (num > n) { cout << 0; break; }
			num++;
	}

}