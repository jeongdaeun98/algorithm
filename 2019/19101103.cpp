#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
bool visited[50][50] = {false};
int location[50][50],n,m,r,c,d,answer = 0;
int directx[] = { -1,0,1,0 };
int directy[] = { 0,1,0,-1 };
void initLocation() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> location[i][j];
		}
	}
}
int turndirection(int direction) {
	switch (direction) {
	case 0 :
		return 3;
	case 1 :
		return 0;
	case 2 :
		return 1;
	default :
		return 2;
	}
}
int backdirection(int direction) {
	switch (direction) {
	case 0 :
		return 2;
	case 1 :
		return 3;
	case 2 :
		return 0;
	default :
		return 1;
	}
}
int bfs() {
	queue<tuple<int, int,int>> q;
	q.push(make_tuple(r,c,d));
	visited[r][c] = true;
	answer++;
	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int direct = get<2>(q.front());
		int flag = false,presentdirect = direct,dx,dy;
		q.pop();
		for (int i = 0; i < 4; i++) {
			presentdirect = turndirection(presentdirect);
			dx = directx[presentdirect] + x;
			dy = directy[presentdirect] + y;
			if (dx < n && dx >= 0 && dy < m && dy >= 0 && !visited[dx][dy] && location[dx][dy] == 0) {
				q.push(make_tuple(dx, dy, presentdirect));
				visited[dx][dy] = true;
				answer++;
				flag = true;
				break;
			}
		}
		if (!flag) {
			presentdirect = backdirection(direct);
			dx = directx[presentdirect] + x;
			dy = directy[presentdirect] + y;
			if (dx < n && dx >= 0 && dy < m && dy >= 0 && location[dx][dy] == 0)
				q.push(make_tuple(dx, dy, direct));
		}
	}
	return answer;
}

int main(void) {
	cin >> n >> m >> r >> c >> d;
	initLocation();
	cout << bfs();
}