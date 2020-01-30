#include <iostream>
#include <queue>
using namespace std;
int n, m, answer = 0,minanswer = 999999;
char board[51][51];
int directx[] = { 1,-1,0,0 };
int directy[] = { 0,0,1,-1 };
bool visited[51][51] = {false};
void initBoard() {
	for (int i = 0; i < n; i++ ) 
		cin >> board[i];
}
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}
}
void dfs(int x, int y, char value,pair<int,int> start, pair<int,int> end) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dx >= start.first && dx < end.first&& dy >= start.second && dy < end.second && !visited[dx][dy] && board[dx][dy] == board[x][y]) {
			answer++;
			char origin = board[dx][dy];
			board[dx][dy] = value;
			dfs(dx, dy,origin,start,end);
			board[dx][dy] = origin;
		}
	}
}
void searchDfs(int x, int y) {
	pair<int, int> start, end;
	start = make_pair(x, y);
	end = make_pair(x + 8, y + 8);
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (!visited[i][j]) {
				if (board[i][j] != 'W')
					dfs(i, j, 'W', start, end);
				else
					dfs(i, j, 'B',start, end);
			}
		}
	}
}
void searchBoard() {
	for (int i = 0; i < n; i++) {
		if (n - i < 8)
			break;
		for (int j = 0; j < m; j++) {
			if (m - j >= 8) {
				initVisited();
				searchDfs(i, j);
				if (minanswer > answer) 
					minanswer = answer;		
				answer = 1;
				initVisited();
				if (board[i][j] == 'W') board[i][j] = 'B';
				else board[i][j] = 'W';
				searchDfs(i, j);
				if (minanswer > answer)
					minanswer = answer;
				answer = 0;
				if (board[i][j] == 'W') board[i][j] = 'B';
				else board[i][j] = 'W';
			}
			else break;
		}
	}
}
int main(void) {
	cin >> n >> m;
	initBoard();
	if (n > 8 || m > 8)
		searchBoard();
	else {
		searchDfs(0, 0);
		if (minanswer > answer)
			minanswer = answer;
		initVisited();
		answer = 1;
		if (board[0][0] == 'W') board[0][0] = 'B';
		else board[0][0] = 'W';
		searchDfs(0, 0);
		if (minanswer > answer)
			minanswer = answer;
	}
	cout << minanswer;
}