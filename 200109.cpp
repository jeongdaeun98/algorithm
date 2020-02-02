#include <string>
#include <vector>
#include <stack>
using namespace std;
int* visited;
void initVisited(int n) {
	visited = new int[n];
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
}
void dfs(int x, vector<vector<int>>& computers, int n) {
	visited[x] = 1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && computers[x][i])
			dfs(i, computers, n);
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	initVisited(n);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, computers, n);
			answer++;
		}
	}
	return answer;
}