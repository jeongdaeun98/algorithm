#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (char c : s) {
		char start;
		if (c == ' ') {
			answer += c;
			continue;
		}
		if (c >= 'a')
			start = 'a';
		else
			start = 'A';
		answer += (c + n - start) % 26 + start;
	}
	return answer;
}