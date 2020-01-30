#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s) {
	stack<char> st;
	stack<char> garbage;
	while (!st.empty()) {
		if (!garbage.empty() && garbage.top() == st.top()) 
			garbage.pop();
		else 
			garbage.push(st.top());
		st.pop();
	}
	if (!garbage.empty())return 0;
	else return 1;
}