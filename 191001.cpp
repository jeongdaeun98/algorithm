#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k,**paper,answer = 0;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
bool **check;
vector<int> answervector;
void initCheck() {
	check = new bool *[m];
	for (int i = 0; i < m; i++)
		check[i] = new bool[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}
void initPaper() {
	int x1, y1, x2, y2;
	cin >> m >> n >> k;
	paper = new int *[m];
	for (int i = 0; i < m; i++)
		paper[i] = new int[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			paper[i][j] = 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = x1; j < x2; j++) {
			for (int z = y1; z < y2; z++)
				paper[j][z] = 1;
		}
	}
}
void dfs(int x, int y) {
	check[x][y] = true;
	answer++;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dx < m && dx >= 0 && dy < n && dy >= 0 && !check[dx][dy] && paper[dx][dy] == 0)
			dfs(dx, dy);
	}
}
void searchdfs() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] == 0 && !check[i][j]) {
				dfs(i, j);
				answervector.push_back(answer);
				answer = 0;
			}
		}
	}
}
int main(void) {
	initPaper();
	initCheck();
	searchdfs();
	sort(answervector.begin(), answervector.end());
	cout << answervector.size() << "\n";
	for (int i = 0; i < answervector.size(); i++)
		cout << answervector[i] << " ";
}