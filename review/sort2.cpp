#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool sorting(string &a, string &b) {
	string str1, str2;
	str1.append(a); str1.append(b); str2.append(b); str2.append(a);
	if (str1 > str2) return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> numberToString;
	for (int i = 0; i < numbers.size(); i++)
		numberToString.push_back(to_string(numbers[i]));
	sort(numberToString.begin(), numberToString.end(), sorting);
	for (int i = 0; i < numberToString.size(); i++)
		answer += numberToString[i];
	if(atoi(answer.c_str()) == 0) return "0";
	return answer;
}