#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;
	
	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}
string compareStringAndChangeWord(string str) {
	if (str.compare("Enter"))
		return "���Խ��ϴ�.";
	else
		return "�������ϴ�.";
}
vector<string> solution(vector<string> record) {
	vector<string> answer;
	queue<pair<string, string>> answerQueue;
	unordered_map<string, string> nickname;
	for (string info : record) {
		vector <string> splitString = split(info, ' ');
		answerQueue.push(make_pair(splitString[0], splitString[1]));
		if(nickname.find(splitString[1]) == nickname.end())
			nickname.insert(make_pair(splitString[1], splitString[2]));
		else if(splitString[0].compare("Leave")) {
			nickname.erase(splitString[1]);
			nickname.insert(make_pair(splitString[1], splitString[2]));
		}
	}
	while (!answerQueue.empty()) {
		pair<string, string> answerPair = answerQueue.front();
		answerQueue.pop();
		if (answerPair.first.compare("Change")!= 0) {
			string word = compareStringAndChangeWord(answerPair.first);
			answer.push_back(nickname[answerPair.second] + "���� " + word);
		}
	}
	
	return answer;
}