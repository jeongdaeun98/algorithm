#include <iostream>
#include <queue>
using namespace std;
int n, m,**tomato,**depth,answer = 0;
bool **visited;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void initVisited() {
	visited = new bool*[n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}
void initTomato() {
	tomato = new int*[n];
	for (int i = 0; i < n; i++)
		tomato[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
}
void initDepth() {
	depth = new int*[n];
	for (int i = 0; i < n; i++)
		depth[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			depth[i][j] = 0;
		}
	}
}
void bfs() {
	pair<int, int> node;
	node = q.front();
	visited[node.first][node.second] = true;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = directx[i] + node.first;
			int dy = directy[i] + node.second;
			if (dx >= 0 && dx < n && dy >= 0 && dy < m &&tomato[dx][dy] == 0 && !visited[dx][dy]) {
				q.push(make_pair(dx, dy));
				visited[dx][dy] = true;
				tomato[dx][dy] = 1;
				depth[dx][dy] = depth[node.first][node.second] + 1;
				answer = depth[dx][dy];
			}
		}
		if (!q.empty()) node = q.front();
	}
}
int main(void) {
	cin >> m >> n;
	initTomato();
	initVisited();
	initDepth();
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) { answer = -1; break; }
		}
	}
	cout << answer;
}