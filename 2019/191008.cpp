#include <iostream>
#include <queue>
#include <string>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
string *treasure;
int n, m, **depth, maxNum = 0;
bool **visited;
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}
}
void initPlaceVisited() {
	visited = new bool*[n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[m];
}
void initTreasure() {
	treasure = new string[n];
	for (int i = 0; i < n; i++)
		cin >> treasure[i];
}
void initPlaceDepth() {
	depth = new int*[n];
	for (int i = 0; i < n; i++)
		depth[i] = new int[m];
}
void initDepth() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			depth[i][j] = 0;
	}
}

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	pair<int, int> node;
	q.push(make_pair(x, y));
	node = q.front();
	visited[x][y] = true;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = directx[i] + node.first;
			int dy = directy[i] + node.second;
			if (dx < n && dx >= 0 && dy < m && dy >= 0 && !visited[dx][dy] && treasure[dx][dy] == 'L') {
				visited[dx][dy] = true;
				q.push(make_pair(dx, dy));
				depth[dx][dy] = depth[node.first][node.second] + 1;
				if (maxNum < depth[dx][dy])
					maxNum = depth[dx][dy];
			}
			else if (dx < n && dx >= 0 && dy < m && dy >= 0 && !visited[dx][dy])
				visited[dx][dy] = true;
		}
		if (!q.empty()) node = q.front();
	}
}
void searchBfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && treasure[i][j] == 'L') {
				bfs(i, j);
				initDepth();
				initVisited();
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	initTreasure();
	initPlaceDepth();
	initDepth();
	initPlaceVisited();
	initVisited();
	searchBfs();
	cout << maxNum;
}