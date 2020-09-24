#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> *virus;
bool *visited;
int n,t,answer = 0 ;
void initVirus() {
	virus = new vector<int>[n];
	for (int i = 0; i < t; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		virus[num1 -1].push_back(num2 - 1);
		virus[num2 -1].push_back(num1- 1);
	}
}
void initVisited() {
	visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
}
void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int node = q.front();
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < n; i++) {
			if (!visited[i] && find(virus[node].begin(), virus[node].end(), i) != virus[node].end()) {
				q.push(i);
				visited[i] = true;
				answer++;
			}
		}
		if (!q.empty())node = q.front();
	}
}
int main(void) {
	cin >> n >> t;
	initVirus();
	initVisited();
	bfs();
	cout << answer;
}