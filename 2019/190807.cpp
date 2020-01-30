#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

void init(int **matrix,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}

}
void putValue(int **matrix, int m) {
	for(int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		matrix[j - 1][k - 1] = 1;
		matrix[k - 1][j - 1] = 1;
	}
}
queue<int> dfs(int **matrix, int n, int v) {
	stack<int>stack;
	queue<int> result;
	int node;
	int size = 0;
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	stack.push(v - 1);
	node = stack.top();
	result.push(v);
	visited[v - 1] = true;
	while (!stack.empty() && size != n) {
		for (int j = 0; j < n; j++) {
			if (matrix[node][j] == 1 && visited[j] == false) {
				stack.push(j);
				result.push(j + 1);
				visited[j] = true;
				break;
			}
		}
		size = result.size();
		if (stack.top() == node && size != n)stack.pop();
		if(!stack.empty())
			node = stack.top();
	}

	
	return result;
}
queue<int> bfs(int **matrix, int n, int v) {
	queue<int> q;
	queue<int> result;
	int node;
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	q.push(v - 1);
	visited[v - 1] = true;
	node = q.front();
	result.push(v);
	while (!q.empty()) {
			q.pop();
			for (int j = 0; j < n; j++) {
				if (matrix[node][j] == 1 && visited[j] == false) {
					q.push(j);
					result.push(j+1);
					visited[j] = true;
				}	
			}
			if(!q.empty())
				node = q.front();
		}
		
	return result;
}
void print(queue<int> result) {
	int size = result.size();
	for (int i = 0; i < size; i++) {
		cout << to_string(result.front()) + " ";
		result.pop();
	}
	cout << "\n";
}
int main(void) {
	while (1) {
		int n, m, v;
		cin >> n >> m >> v;
		queue<int> dfsResult;
		queue<int> bfsResult;
		int **matrix = new int*[n];
		
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
		}
		init(matrix, n);
		putValue(matrix, m);
		dfsResult = dfs(matrix, n, v);
		bfsResult = bfs(matrix, n, v);
		print(dfsResult);
		print(bfsResult);
	}
	
}