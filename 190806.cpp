#include<iostream>
#include<queue>
using namespace std;

void init(bool visited[],int n) {
	for (int i = 0; i < n; i++)
		visited[i] = false;
}

int main(void) {
	int n;
	queue<int> q;
	cin >> n;
	int node;
	bool *visited = new bool[n];
	int **adjacencyMatrix = new int*[n];
	int **routeMatrix = new int*[n];
	for (int i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n];
		routeMatrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjacencyMatrix[i][j];
			routeMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		q.push(i);
		node = q.front();
		init(visited, n);
		while (!q.empty()) {
			q.pop();
			for (int j = 0; j < n; j++) {
				if (adjacencyMatrix[node][j] == 1 && visited[j] == false) {
					q.push(j);
					visited[j] = true;
					routeMatrix[i][j] = 1;
				}
			}
			if(!q.empty())
				node = q.front();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (routeMatrix[i][j] == 1)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << '\n';
	}

}