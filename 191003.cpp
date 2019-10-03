#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v, e,*color, v1, v2;;
bool *visited;
vector<int>	*adj;
void initVisitedAndColor() {
	visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	color = new int[v];
	adj = new vector<int>[v];
}
void getValue() {
	cin >> v >> e;
	initVisitedAndColor();
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		adj[v1 - 1].push_back(v2 - 1);
		adj[v2 - 1].push_back(v1 - 1);
	}
}
void bfs() {
	queue<int> q;
	int node,presentColor = 1;
	for (int i = 0; i < v; i++) {
		if (visited[i]) continue;
		q.push(i);
		visited[i] = true;
		node = q.front();
		color[node] = presentColor * -1;
		while (!q.empty()) {
			q.pop();
			presentColor = color[node] * -1;
			for (int j = 0; j < adj[node].size(); j++) {
				if (!visited[adj[node][j]]) {
					q.push(adj[node][j]);
					visited[adj[node][j]] = true;
					color[adj[node][j]] = presentColor;
				}
				else {
					if (color[adj[node][j]] != presentColor) {
						cout << "NO" << "\n";
						return;
					}
				}
			}
			if (!q.empty())
				node = q.front();
		}
		
	}
	cout << "YES" << "\n";
}
int main(void) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		getValue();
		bfs();
	}	
}