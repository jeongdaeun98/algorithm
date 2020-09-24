#include <iostream>
#include <queue>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
int n, **geography, **depth, number = 1,minnum = 9999999;
bool **visited;
void initDepthPlace() {
	depth = new int *[n];
	for (int i = 0; i < n; i++)
		depth[i] = new int[n];
}
void initDepth() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			depth[i][j] = 0;
	}
}
void initVisitedPlace() {
	visited = new bool *[n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[n];
}
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}
}
void initGeography() {
	geography = new int *[n];
	for (int i = 0; i < n; i++)
		geography[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> geography[i][j];
	}
}
int bfs(int x, int y,int land) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	pair<int, int> node = q.front();
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = directx[i] + node.first;
			int dy = directy[i] + node.second;
			if (dx < n&& dx >= 0 && dy < n && dy >= 0 && !visited[dx][dy] && geography[dx][dy] == 0) {
				q.push(make_pair(dx, dy));
				visited[dx][dy] = true;
				depth[dx][dy] = depth[node.first][node.second] + 1;
			}
			else if (dx < n && dx >= 0 && dy < n && dy >= 0 && !visited[dx][dy] && geography[dx][dy] != land)
				return depth[node.first][node.second];
		}
		if (!q.empty()) node = q.front();
	}
	return 99999999;
}
void searchbfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && geography[i][j] != 0) {
				int depthnum = bfs(i, j,geography[i][j]);
				if (minnum > depthnum) minnum = depthnum;
				initVisited();
				initDepth();
			}
		}
	}
}
void dfs(int x, int y) {
	visited[x][y] = true;
	geography[x][y] = number;
	for (int i = 0; i < 4; i++) {
		int dx = directx[i] + x;
		int dy = directy[i] + y;
		if (dx < n&& dx >= 0 && dy < n && dy >= 0 && !visited[dx][dy] && geography[dx][dy] == 1)
			dfs(dx, dy);
	} 
}
void searchdfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && geography[i][j] == 1) {
				dfs(i, j);
				number++;
			}
		}
	}
}

int main(void) {
	cin >> n;
	initDepthPlace();
	initVisitedPlace();
	initDepth();
	initVisited();
	initGeography();
	searchdfs();
	initDepth();
	initVisited();
	searchbfs();
	cout << minnum;
}