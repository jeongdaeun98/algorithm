#include <iostream>
using namespace std;

int main(void) {
	int n, k,money,count = 0,c;

	cin >> n;
	cin >> k;
	int *num = new int[n];
	
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	money = k;
	if (money < 50000) {
		for (int i = n - 2; i >= 0; i--) {
			if (num[i + 1] > money && num[i] <= money) {
				c = money / num[i];
				money = money - (num[i] * c);
				count = count + c;
			}
		}
	}
	else if (money >= 50000) {
		c = money / num[n - 1];
		money = money - (num[n - 1] * c);
		count = count + c;
		for (int i = n - 2; i >= 0; i--) {
			if (num[i + 1] > money && num[i] <= money) {
				c = money / num[i];
				money = money - (num[i] * c);
				count = count + c;
			}
		}
	}

	cout << count;
}