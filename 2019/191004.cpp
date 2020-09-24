#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool **visited;
string *maze;
int n, m,**answer;
int directx[] = {0,0,1,-1};
int directy[] = {1,-1,0,0};
void initAnswer() {
	answer = new int *[n];
	for (int i = 0; i < n; i++)
		answer[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			answer[i][j] = 0;
	}
}
void initVisited() {
	visited = new bool *[n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
	
}
void initMaze() {
	maze = new string [n];
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
}
void bfs() {
	queue<pair<int,int>> q;
	pair<int,int> node;
	q.push(make_pair(0,0));
	visited[0][0] = true;
	node = q.front();
	answer[0][0] = 1;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = directx[i] + node.first;
			int dy = directy[i] + node.second;
			if (dx < n && dx >= 0 && dy < m && dy >= 0 && !visited[dx][dy] && maze[dx][dy] == '1') {
				q.push(make_pair(dx, dy));
				visited[dx][dy] = true;
				answer[dx][dy] = answer[node.first][node.second] + 1;
			}
			else if (dx < n && dx >= 0 && dy < m && dy >= 0 && maze[dx][dy] == '0')
				visited[dx][dy] = true;
		}
		if (!q.empty()) 
			node = q.front();
	}
}
int main(void) {
	cin >> n >> m;
	initMaze();
	initVisited();
	initAnswer();
	bfs();
	cout << answer[n-1][m-1];
}