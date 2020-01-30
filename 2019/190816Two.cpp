#include <iostream>
#include <string>
#include <stack>

using namespace std;

string checkVPS(string arrangement) {
	string answer = "YES";
	stack<char> charStack;
	int size = arrangement.size();

	for (int i = 0; i < size; i++) {
		if (arrangement[i] == '(') {
			charStack.push(arrangement[i]);
		}
		else {
			if (!charStack.empty())
				charStack.pop();
			else
				return "No";
		}
	}
	if (!charStack.empty()) return "No";

	return answer;
}
int main(void) {
	int t;
	string answer;
	string arrangement;
	cin>>t;
	for (int i = 0; i < t; i++) {
		cin>>arrangement;
		cout << checkVPS(arrangement);
		if (i != t - 1) cout << "\n";
	}
}