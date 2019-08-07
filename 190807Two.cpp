#include<iostream>
#include<queue>
#include<string>
#include<map>
#include <vector>
using namespace std;

void init(int n, int **matrix) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
}
void initVisited(bool *visited, int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
}
void putValue(int n, int m, int ** matrix) {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		matrix[a - 1][b - 1] = 1;
		matrix[b - 1][a - 1] = 1;
	}
}
void bfs(int n, int**matrix) {
	bool *visited = new bool[n];
	map<int, vector<int>> m;
	queue<int> q;
	int node;
	initVisited(visited, n);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			q.push(i);
			vector<int> groupNode;
			groupNode.push_back(i);
			node = q.front();
			visited[i] = true;
			while (!q.empty()) {
				q.pop();
				for (int j = 0; j < n; j++) {
					if (matrix[node][j] == 1 && visited[j] == false) {
						q.push(j);
						visited[j] = true;
						groupNode.push_back(j);
					}
				}
				if (!q.empty()) node = q.front();
			}
			if (groupNode.size() != 0)
				m.insert(map<int, vector<int>>::value_type(i, groupNode));
		}
		
	}
	cout << to_string(m.size()) + "\n";
}
int main(void) {
	int n, m;
	cin >> n >> m;
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	
	init(n, matrix);
	putValue(n, m,matrix);
	bfs(n, matrix);
}