#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> answerArray;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			answerArray.push_back(array[j]);
		}
		sort(answerArray.begin(), answerArray.end());
		answer.push_back(answerArray[commands[i][2] - 1]);
	}
	return answer;
}