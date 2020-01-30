#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> remainder;
	vector<pair<int, int>> road;
	while (!road.empty() || remainder.empty()) {
		answer++;
		for (int i = 0; i < road.size();) {
			road[i].first--;
			if (road[i].first == 0) {
				weight += road[i].second;
				road.erase(i);

			}
			else {

			}
		}
		if (!remainder.empty() && (road.empty() || weight >= remainder.front() )) {
			road.push_back(make_pair(bridge_length, remainder.front()));
			weight -= remainder.front();
			remainder.pop();
		}
	}
	return answer;
}