#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int x, y, n, m, *depth;
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
void initDepth(){
	depth = new int[n];
	for (int i = 0; i < n; i++)
		depth[i] = 0;
}
void bfs() {
	queue<int> q;
	q.push(x - 1);
	int node = q.front();
	visited[x - 1] = true;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < adj[node].size(); i++) {
			if (!visited[adj[node][i]]) {
				q.push(adj[node][i]);
				depth[adj[node][i]] = depth[node] + 1;
				visited[adj[node][i]] = true;
			}
		}
		if (!q.empty()) node = q.front();
	}
}
int main(void) {
	cin >> n >> x >> y >> m;
	initAdj();
	initDepth();
	initVisited();
	bfs();
	if (depth[y - 1] == 0) cout << -1;
	else
		cout << depth[y - 1];
}