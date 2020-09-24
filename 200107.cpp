#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<pair<int, int>> pairAnswer;
	int students[][10] = { { 1,2,3,4,5 },{ 2,1,2,3,2,4,2,5 },{ 3,3,1,1,2,2,4,4,5,5 } };
	int studentsSize[] = { 5,8,10 };
	for (int i = 0; i < 3; i++) {
		pair<int, int> count;
		count.first = 0;
		count.second = i;
		for (int j = 0; j < answers.size(); j++) {
			if (answers[j] == students[i][j%studentsSize[i]])
				count.first++;
		}
		pairAnswer.push_back(count);
	}
	sort(pairAnswer.begin(), pairAnswer.end());
	answer.push_back(pairAnswer[2].second + 1);
	if (pairAnswer[2].first == pairAnswer[1].first) answer.push_back(pairAnswer[1].second + 1);
	if (pairAnswer[2].first == pairAnswer[0].first) answer.push_back(pairAnswer[0].second + 1);
	sort(answer.begin(), answer.end());
	return answer;
}