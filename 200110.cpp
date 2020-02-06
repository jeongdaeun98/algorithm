#include <iostream>
#include <string>
using namespace std;
int main(void) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string sentence;
		cin >> sentence;
		int number = 0;
		bool correctTrue = true;
		for (char c : sentence) {
			if (c == '(')
				number++;
			else if (c == ')' && number > 0)
				number--;
			else {
				correctTrue = false;
				break;
			}
		}
		if (number != 0 || !correctTrue ) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}