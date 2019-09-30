#include <iostream>
#include<algorithm>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
int **lab, n, m, answer = 0, maxanswer = 0;
bool **check;
void initCheck() {
	check = new bool *[n];
	for (int i = 0; i < n; i++)
		check[i] = new bool[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
		}
	}
}
void initLab() {
	lab = new int *[n];
	for (int i = 0; i < n; i++)
		lab[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}
}
void fourwaydfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && !check[dx][dy] && lab[dx][dy] == 0) {
			lab[dx][dy] = 3;
			fourwaydfs(dx, dy);
		}
	}
}
void searchdfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && lab[i][j] == 2) 
				fourwaydfs(i, j);
		}
	}
}
void countSafeZoneAndInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0)
				answer++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 3)
				lab[i][j] = 0;
		}
	}
}
void combination(int depth) {
	if (depth == 3) {
		searchdfs();
		initCheck();
		countSafeZoneAndInit();
		if (maxanswer < answer)
			maxanswer = answer;
		answer = 0;
		return; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				combination(depth + 1);
				lab[i][j] = 0;
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	initLab();
	initCheck();
	combination(0);
	cout << maxanswer;
}