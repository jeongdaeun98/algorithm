#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool sorting(char a, char b) {
	if (a > b) return true;
	else return false;
}
string solution(string s) {
	string answer = "";
	vector<char> str;
	for (int i = 0; i < s.length(); i++)
		str.push_back(s[i]);
	sort(str.begin(), str.end(), sorting);
	for (char c : str)
		answer += c;
	return answer;
}