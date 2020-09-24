#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, presentweight = weight;
	queue<int> remainder;
	for (auto i : truck_weights)
		remainder.push(i);
	vector<pair<int, int>> road;
	while (!remainder.empty() || !road.empty()) {
		answer++;
		for (int i = 0; i < road.size();) {
			road[i].first -= 1;
			if (road[i].first == 0) {
				presentweight += road[i].second;
				road.erase(road.begin() + i);
			}
			else i++;
		}
		if (!remainder.empty() && (road.empty() || presentweight >= remainder.front())) {
			road.push_back(make_pair(bridge_length, remainder.front()));
			presentweight -= remainder.front();
			remainder.pop();
		}

	}
	return answer;
}