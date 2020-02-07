#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	int c;
	cin >> c;
	cin.ignore();
	while (c--) {
		string s;
		getline(cin, s);
		string answer;
		stack<char> ansStack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') 
				ansStack.push(s[i]);
			if (s[i] == ' ' || i == s.size() - 1) {
				while (!ansStack.empty()) {
					answer += ansStack.top();
					ansStack.pop();
				}
				if(s[i] == ' ')
					answer += s[i];
				continue;
			}
		}
		cout << answer << "\n";
	}
}