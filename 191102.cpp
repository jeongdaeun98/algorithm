#include <iostream>
using namespace std;
int ice[301][301];
int visited[301][301] = { 0, };
int n, m,answer = 0,team = 0;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}
void initIce() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];
	}
}
void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]  && ice[dx][dy] == 0) {
			if(ice[x][y] > 0)
				--ice[x][y];
		}
		else if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy] && ice[dx][dy] != 0)
			dfs(dx, dy);
		
	}
}
void searchDfs() {
	while (1) {
		team = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (!visited[i][j] && ice[i][j] != 0) {
					team++;
					dfs(i, j);
				}
			}
		}
		initVisited();
		if (team >= 2) { cout << answer; return; }
		if (team == 0) { cout << 0; return; }
		answer++;
	}
}
int main(void) {
	initIce();
	searchDfs();
}