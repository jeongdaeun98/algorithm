#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int t,num;
	stack<int> numStack;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		if (num != 0)
			numStack.push(num);
		else
			numStack.pop();
	}
	num = 0;
	if (numStack.empty()) cout << 0;
	else {
		while (!numStack.empty()) {
			num += numStack.top();
			numStack.pop();
		}
		cout << num;
	}
}