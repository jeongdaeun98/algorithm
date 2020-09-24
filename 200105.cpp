#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<pair<int, int>> topStack;
	int *answerArray = new int[heights.size()];
	for (int i = 0; i < heights.size(); i++)
		answerArray[i] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> remainderQueue;
	bool remainderWhileTrue = true;
	for (int i = 0; i < heights.size(); i++)
		topStack.push(make_pair(heights[i], i + 1));
	while (!topStack.empty()) {
		pair<int, int> presentNum = topStack.top();
		topStack.pop();
		while (remainderWhileTrue) {
			if (!remainderQueue.empty() && remainderQueue.top().first < presentNum.first) {
				answerArray[remainderQueue.top().second - 1] = presentNum.second;
				remainderQueue.pop();
			}
			else remainderWhileTrue = false;
		}
		remainderQueue.push(presentNum);
		remainderWhileTrue = true;
	}
	for (int i = 0; i < heights.size(); i++)
		answer.push_back(answerArray[i]);

	return answer;
}