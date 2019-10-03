#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int n, m,answer = 0,*depth,*kevin;
bool *visited;
void initAdj() {
	adj = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1 - 1].push_back(v2 - 1);
		adj[v2 - 1].push_back(v1 - 1);
	}
}
void initVisited() {
	visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
}
void bfs(int index) {
	queue<int> q;
	q.push(index);
	visited[index] = true;
	int node = q.front();
	depth[node] = 0;
	while (!q.empty()) {
		q.pop();
		answer += depth[node];
		for (int i = 0; i < adj[node].size(); i++) {
			if (!visited[adj[node][i]]) {
				q.push(adj[node][i]);
				visited[adj[node][i]] = true;
				depth[adj[node][i]] = depth[node] + 1;
			}
		}
		if (!q.empty())
			node = q.front();
	}
}

int main(void) {
	cin >> n >> m;
	kevin = new int[n];
	depth = new int[n];
	initAdj();
	for (int i = 0; i < n; i++) {
		initVisited();
		bfs(i);
		kevin[i] = answer;
		answer = 0;
	}
	int min = 0;
	for (int i = 1; i < n; i++) {
		if (kevin[min] > kevin[i])
			min = i;
	}
	cout << min + 1;
}