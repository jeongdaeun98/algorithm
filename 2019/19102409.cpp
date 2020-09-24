#include<string>

using namespace std;

bool solution(string s){
	bool answer = true;
	int open = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			open++;
		else if (s[i] == ')' && open != 0)
			open--;
		else if (s[i] == ')' && open == 0)
			answer = false;
	}
	if (open != 0) answer = false;
	return answer;
}