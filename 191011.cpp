#include<iostream>
#include<queue>
using namespace std;
int directx[] = {-1,-1,-2,-2,1,1,2,2};
int directy[] = {2,-2,1,-1,-2,2,-1,1};
int t,n,depth[300][300],chess[300][300];
void initDepth() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			depth[i][j] = 0;
	}
}
void initChess(int x1,int y1, int x2, int y2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			chess[i][j] = 0;
	}
	chess[x1][y1] = 1;
	chess[x2][y2] = 1;
}
int bfs(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x1, y1));
	depth[x1][y1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int dx = directx[i] + x;
			int dy = directy[i] + y;
			if (dx >= n || dx < 0 || dy >= n || dy < 0) continue;
			if (depth[dx][dy] || dx ==x1 && dy==y1) continue;
			if (chess[dx][dy] == 0) {
				q.push(make_pair(dx, dy));
				depth[dx][dy] = depth[x][y] + 1;
			}
			else if (chess[dx][dy] == 1) 
				return depth[x][y] + 1;
			

		}
	}
}
int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		initChess(x1,y1,x2,y2);
		initDepth();
		int answer = bfs(x1, y1, x2, y2);
		cout << answer << "\n";
	}
}