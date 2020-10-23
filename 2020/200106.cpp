#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<pair<int, int>>road;
	queue<int> remainder;
	for (int i : truck_weights)remainder.push(i);
	while (!remainder.empty() || !road.empty()) {
		answer++;
		for (int i = 0; i < road.size();) {
			road[i].first--;
			if (road[i].first == 0) {
				weight += road[i].second;
				road.erase(road.begin() + i);
			}
			else i++;
		}
		if (!remainder.empty() && (road.empty() || weight >= remainder.front())) {
			road.push_back(make_pair(bridge_length, remainder.front()));
			weight -= remainder.front();
			remainder.pop();
		}
	}
	return answer;
}