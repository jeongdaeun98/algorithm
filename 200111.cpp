#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(pair<int, double> a, pair<int, double> b) {
	if (a.second > b.second) return true;
	else if (a.second < b.second) return false;
	else if (a.second == b.second && a.first < b.first) return true;
	else return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> failureNums(N);
	vector<int> successfulNums(N);
	vector<pair<int, double>>failureRatings(N);
	for (int stage : stages) {
		for (int i = 0; i < N; i++) {
			if (stage == i + 1)
				failureNums[i]++;
			if (stage >= i + 1)
				successfulNums[i]++;
		}
	}
	for (int i = 0; i < failureNums.size(); i++) {
		failureRatings[i].first = i;
		if (successfulNums[i] == 0) failureRatings[i].second = 0;
		else failureRatings[i].second = (double)failureNums[i] / (double)successfulNums[i];

	}
	sort(failureRatings.begin(), failureRatings.end(), compare);
	for (pair<int, double> failurePair : failureRatings)
		answer.push_back(failurePair.first + 1);

	return answer;
}