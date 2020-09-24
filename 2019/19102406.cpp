#include <vector>
#include <queue>
#include <functional>
using namespace std;
int depth[51] = { 0 };
bool visited[51] = { false };
vector<pair<int, int>>street[51];

void initStreet(vector<vector<int>> &road) {
	for (int i = 0; i < road.size(); i++) {
		street[road[i][0]].push_back(make_pair(road[i][2],road[i][1]));
		street[road[i][1]].push_back(make_pair(road[i][2],road[i][0]));
	}
}
void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		visited[node.second] = true;
		pq.pop();
		for (auto i : street[node.second]) {
			if (visited[i.second]) continue;
			if (depth[i.second]  == 0 || depth[i.second] > node.first + i.first){
				depth[i.second] = node.first + i.first;
				pq.push(make_pair(depth[i.second],i.second));
		}
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	initStreet(road);
	dijkstra();
	for (int i = 1; i <= N; i++) {
		if (depth[i] <= K)
			answer++;
	}
	return answer;
}