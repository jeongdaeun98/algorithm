#include <iostream>
#include <queue>
using namespace std;
int computer[101][101];
int visited[101];
queue<int> q;
int computerNum;
void initVisited() {
	for (int i = 0; i < computerNum; i++)
		visited[i] = 0;
}
void initComputer(int lengthNum) {
	for (int i = 0; i < lengthNum; i++) {
		int x, y;
		cin >> x >> y;
		computer[x-1][y-1] = 1;
		computer[y-1][x-1] = 1;
	}
}
void bfs() {
	int node;
	q.push(0);
	visited[0] = 1;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < computerNum; i++) {
			if (!visited[i] && computer[node][i] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
int main(void) {
	int lengthNum;
	cin >> computerNum >> lengthNum;
	initVisited();
	initComputer(lengthNum);
	bfs();
	int count = 0;
	for (int i = 0; i < computerNum; i++) {
		if (visited[i]) count++;
	}
	cout << count -1;
}