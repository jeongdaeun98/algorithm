#include <string>
#include <vector>
#include <set>
using namespace std;
vector<int> answer;
void searchfalseWord(int personNum,vector<string> &word) {
	set<string> word_set;
	for (int i = 1; i < word.size(); i++) {
		word_set.insert(word[i -1]);
		if (word_set.find(word[i]) == word_set.end()) {
				if (word[i][0] != word[i-1][word[i - 1].size() - 1]) {
					answer.push_back(i%personNum + 1);
					answer.push_back(i / personNum + 1);
					break;
				}
		}
		else {
			answer.push_back(i % personNum + 1);
			answer.push_back(i / personNum + 1);
			break;
		}
	}
}
	vector<int> solution(int n, vector<string> words) {
		searchfalseWord(n,words);
		if (!answer.empty()) return answer;
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}