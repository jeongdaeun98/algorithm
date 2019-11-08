#include <iostream>
#include <queue>
#include <string>
using namespace std;
string land[51];
int value[51][51] = {0};
int watervalue[51][51] = {0};
int r, c,waternum = 0;
bool passedD = false;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
pair<int, int> *wposition;
pair<int, int> sposition;
void initLand() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> land[i];
}
void searchSpositionAndWposition() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (land[i][j] == 'S')
				sposition = make_pair(i, j);
			else if (land[i][j] == '*')
				waternum++;
		}
	}
	wposition = new pair<int, int>[waternum];
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (land[i][j] == '*') {
				wposition[k] = make_pair(i, j);
				k++;
			}
			if (waternum == k) break;
		}
	}
}
void bfs() {
	queue<pair<int, int>>q;
	q.push(sposition);
	queue<pair<int, int>> *q2 = new queue<pair<int, int>>[waternum];
	for (int i = 0; i < waternum; i++)
		q2[i].push(wposition[i]);
	pair<int, int> *waternode = new pair<int, int>[waternum];
	int *waterdx = new int[waternum];
	int *waterdy = new int[waternum];
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < waternum; i++) {
			if (q2[i].empty()) continue;
			waternode[i] = q2[i].front();
			q2[i].pop();
		}
			for (int j = 0; j < waternum; j++) {
				while (1) {
					for (int i = 0; i < 4; i++) {
					waterdx[j] = waternode[j].first + directx[i];
					waterdy[j] = waternode[j].second + directy[i];
					if (waterdx[j] < r && waterdx[j] >= 0 && waterdy[j] < c && waterdy[j] >= 0 &&
						(land[waterdx[j]][waterdy[j]] == '.' || land[waterdx[j]][waterdy[j]] == 'S')) {
						watervalue[waterdx[j]][waterdy[j]] = watervalue[waternode[j].first][waternode[j].second] + 1;
						land[waterdx[j]][waterdy[j]] = '*';
						q2[j].push(make_pair(waterdx[j], waterdy[j]));
					}
				}
					if (!q2[j].empty() && watervalue[waternode[j].first][waternode[j].second] == watervalue[q2[j].front().first][q2[j].front().second]) {
						waternode[j] = q2[j].front();
						q2[j].pop();
					}
					else break;
			}
		}
		while (1) {
			for (int i = 0; i < 4; i++) {
				int dx = node.first + directx[i];
				int dy = node.second + directy[i];
				if (dx < r && dx >= 0 && dy >= 0 && dy < c && land[dx][dy] == '.') {
					value[dx][dy] = value[node.first][node.second] + 1;
					land[dx][dy] = 'S';
					q.push(make_pair(dx, dy));
				}
				if (dx < r && dx >= 0 && dy >= 0 && dy < c && land[dx][dy] == 'D') {
					cout << value[node.first][node.second] + 1;
					passedD = true;
					return;
				}
			}
			if (!q.empty() && value[node.first][node.second] == value[q.front().first][q.front().second]) {
				node = q.front();
				q.pop();
			}
			else break;
		}
		
	}
}

int main(void) {
	initLand();
	searchSpositionAndWposition();
	bfs();
	if (!passedD) cout << "KAKTUS";
}