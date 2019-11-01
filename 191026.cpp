#include <cstdlib>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <functional>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
vector<vector<int>> landland;
int **value;
priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
bool **visited;
int n, h, resultanswer = 0;
void initVisited() {
	visited = new bool*[n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}
}
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = directx[i] + x;
		int dy = directy[i] + y;
		if (dx < n && dx >= 0 && dy < n && dy >= 0 && !visited[dx][dy] && abs(landland[dx][dy] - landland[x][y]) <= h) {	
			dfs(dx, dy);
		}
		else if (dx < n && dx >= 0 && dy < n && dy >= 0 && !visited[dx][dy] && abs(landland[dx][dy] - landland[x][y]) > h) {
			q.push(make_tuple(abs(landland[dx][dy] - landland[x][y]),dx,dy));
		}
	}
	


}
void searchDfs() {
	dfs(0, 0);
	while(!q.empty()){
		tuple<int,int,int> node = q.top();
		q.pop();
		if (!visited[get<1>(node)][get<2>(node)]) {
			resultanswer += get<0>(node);
			dfs(get<1>(node), get<2>(node));
		}
	}
}
int solution(vector<vector<int>> land, int height) {
	landland = land;
	n = landland.size();
	h = height;
	initVisited();
	searchDfs();
	return resultanswer;
}