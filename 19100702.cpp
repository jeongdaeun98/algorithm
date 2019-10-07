#include <iostream>
#include <queue>
using namespace std;
int directx[] = {-1,1,2};
int n, k,minNum = 99999999,*depth;
bool *visited;
void initDepth() {
	depth = new int[100001];
	for (int i = 0; i < 100001; i++)
		depth[i] = 0;
}
void initVisited() {
	visited = new bool[100001];
	for (int i = 0; i < 100001; i++)
		visited[i] = false;
}
void bfs() {
	queue<int> q;
	q.push(n);
	int node = q.front(), dx;
	visited[n] = true;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i < 2)
				dx = directx[i] + node;
			else
				dx = directx[i] * node;
			if (dx <= 100000 && dx >= 0 && !visited[dx]) {
				q.push(dx);
				visited[dx] = true;
				depth[dx] = depth[node] + 1;
			}
		}
		if (!q.empty()) node = q.front();
	}
}
int main(void) {
	cin >> n >> k;
	initDepth();
	initVisited();
	bfs();
	cout << depth[k];
}