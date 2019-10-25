#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "",token;
	vector<int> num;
	stringstream ss(s);
	while (getline(ss, token, ' '))
		num.push_back(atoi(token.c_str()));
	sort(num.begin(), num.end());
	answer = answer + to_string(num[0]) + " ";
	answer = answer + to_string(num[num.size() - 1]);

	return answer;
}