#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<int> finish;
	vector<int> answer;
	int node, ans = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int num = (100 - progresses[i]) / speeds[i];
		int remainder = (100 - progresses[i]) % speeds[i];
		if (remainder != 0) finish.push(num + 1);
		else finish.push(num);
	}
	node = finish.front();
	finish.pop();
	ans++;
	while (!finish.empty()) {
		if (node >= finish.front())
			ans++;
		else {
			answer.push_back(ans);
			ans = 0;
			ans++;
			node = finish.front();
		}
		finish.pop();
	}
	answer.push_back(ans);
	return answer;
}