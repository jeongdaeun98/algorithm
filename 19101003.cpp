#include <iostream>
#include<queue>
#include <tuple>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
char location[1001][1001];
int depth[1001][1001][2],n,m;

int bfs() {
	queue <tuple<int, int, int>> q;
	int dx,dy;
	q.push(make_tuple(0, 0, 0));
	depth[0][0][0] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front()), w = get<2>(q.front());
		q.pop();
		if (x == n - 1 && y == m - 1) return depth[x][y][w];
		for (int i = 0; i < 4; i++) {
			 dx = x + directx[i];
			 dy = y + directy[i];
			 if (dx < n && dx >= 0 && dy < m && dy >= 0 && depth[dx][dy][w]) continue;
				if (dx < n && dx >= 0 && dy < m && dy >= 0 && location[dx][dy] == '0') {
					q.push(make_tuple(dx, dy,w));
					depth[dx][dy][w] = depth[x][y][w] + 1;
				}
				else if (w == 0 && dx < n && dx >= 0 && dy < m && dy >= 0 && location[dx][dy] == '1') {
					q.push(make_tuple(dx, dy,1));
					depth[dx][dy][1] = depth[x][y][w] + 1;
				}
		}
	}
	return -1;
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> location[i];
	cout << bfs();
}