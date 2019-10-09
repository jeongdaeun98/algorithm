#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
int directz[] = { 1,-1 };
bool ***visited;
int ***tomato,***depth,n,m,h,maxnum = 0,nodez;
queue<tuple<int, int,int>> q;
tuple<int, int,int> node;
void initTomato() {
	tomato = new int**[h];
	for (int i = 0; i < h; i++){
		tomato[i] = new int*[n];
		for (int j = 0; j < n; j++) {
			tomato[i][j] = new int[m];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push(make_tuple(j, k, i));
					visited[i][j][k] = true;
				}
			}
		}
	}
}
void initDepth() {
	depth = new int**[h];
	for (int i = 0; i < h; i++) {
		depth[i] = new int*[n];
		for (int j = 0; j < n; j++) {
			depth[i][j] = new int[m];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) 
				depth[i][j][k] = 0;
		}
	}
}
bool IsripeTomatoTrue() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}
void initVisited() {
	visited = new bool**[h];
	for (int i = 0; i < h; i++) {
		visited[i] = new bool*[n];
		for (int j = 0; j < n; j++) 
			visited[i][j] = new bool[m];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) 
				visited[i][j][k] = false;
		}
	}
}
void bfslogic(int dx, int dy, int dz) {
	if (dx >= 0 && dx < n && dy >= 0 && dy < m && dz >= 0 && dz < h && !visited[dz][dx][dy] && tomato[dz][dx][dy] == 0) {
		q.push(make_tuple(dx, dy,dz));
		visited[dz][dx][dy] = true;
		tomato[dz][dx][dy] = 1;
		depth[dz][dx][dy] = depth[get<2>(node)][get<0>(node)][get<1>(node)] + 1;
		if (maxnum < depth[dz][dx][dy])
			maxnum = depth[dz][dx][dy];
		cout << dz << dx << dy << " " << depth[dz][dx][dy] << "\n";
	}
	else if (dx >= 0 && dx < n && dy >= 0 && dy < m && dz >= 0 && dz < h && !visited[dz][dx][dy])
		visited[dz][dx][dy] = true;
}
void bfs() {
	node = q.front();
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 2; i++)
			bfslogic(get<0>(node), get<1>(node), directz[i] + get<2>(node));
		for (int j = 0; j < 4; j++) 
			bfslogic(directx[j] + get<0>(node), directy[j] + get<1>(node), get<2>(node));
			
		if (!q.empty()) 
			node = q.front();
	}
}
int main(void) {
	cin >> m >> n >> h;
	initVisited();
	initTomato();
	initDepth();
	bfs();
	if (IsripeTomatoTrue()) cout << maxnum;
	else cout << -1;
}