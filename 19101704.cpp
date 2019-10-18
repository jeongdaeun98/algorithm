#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
	int answer = 0, leftcount = 0,leftanswer = 0, rightcount = 0, acount = 0;
	if (name[0] != 'A') name[0] - 'A' > 'Z' - name[0] ? answer = 'Z' - name[0] + 1 : answer = name[0] - 'A';
	for (int i = 1; i < name.size(); i++) {
		leftcount++;
		name[i] == 'A' ? acount++ : leftcount - acount < acount ? acount-- : acount = 0;
		name[i] - 'A' > 'Z' - name[i] ? leftanswer += 'Z' - name[i] + 1 : leftanswer += name[i] - 'A';
	}
	leftcount -= acount; leftcount += leftanswer; acount = 0;
	for (int i = name.size() - 1; i > 0; i--) {
		rightcount++;
		name[i] == 'A' ? acount++ : acount = 0;
		name[i] - 'A' > 'Z' - name[i] ? rightcount += 'Z' - name[i] + 1 : rightcount += name[i] - 'A';
	}
	rightcount -= acount;
	answer += min(leftcount, rightcount);

	return answer;
}