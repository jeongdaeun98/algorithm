#include <iostream>
using namespace std;

int n, m,maxsum = 0;
bool *visited;
int *card;
void initVisited() {
	visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
}
void initCard() {
	card = new int[n];
	for (int i = 0; i < n; i++)
		cin >> card[i];
}
void dfs(int depth,int sum) {
	if (depth == 3) {
		if (sum <= m && maxsum < sum) maxsum = sum;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(depth + 1, sum + card[i]);
		visited[i] = false;
	}

}
int main(void) {
	cin >> n >> m;
	initVisited();
	initCard();
	dfs(0, 0);
	cout << maxsum;
}