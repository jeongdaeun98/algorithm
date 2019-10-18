#include <string>
using namespace std;

string solution(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] > '9' && s[i] >= 'a')
			s[i] = s[i] - 'a' + 'A';

		else if (s[i - 1] == ' ' && s[i] > '9' && s[i] >= 'a')
			s[i] = s[i] - 'a' + 'A';

		else if (i != 0 && s[i - 1] != ' ' && s[i] > '9' && s[i] < 'a')
			s[i] = s[i] - 'A' + 'a';

	}
	return s;
}