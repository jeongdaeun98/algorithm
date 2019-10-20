#include <iostream>
#include <queue>
using namespace std;
int depth[1000001] = {0};
int visited[1000001] = { 0 };
int direct[2];
int f, s, g;
void bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int x = q.front(),dx;
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (i == 0) dx = x + direct[i];
			else dx = x - direct[i];
			if (dx <= f && !visited[dx]) {
				q.push(dx);
				depth[dx] = depth[x] + 1;
				visited[dx] = 1;
			}
		}
	}
}
int main(void) {
	cin >> f >> s >> g >> direct[0] >> direct[1];
	bfs();
	if (s == g) cout << 0;
	else if (depth[g] != 0)
		cout << depth[g];
	else
		cout << "use the stairs";
}