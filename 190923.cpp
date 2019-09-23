#include <iostream>
#include <vector>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
bool **check;
int m, n, answer = 0, **vegetablearray;
void initarray() {
	vegetablearray = new int*[n];
	for (int i = 0; i < n; i++)
		vegetablearray[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vegetablearray[i][j] = 0;
		}
	}
}
void initcheck() {
	check = new bool*[n];
	for (int i = 0; i < n; i++)
		check[i] = new bool[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dy < m && dy >= 0 && dx < n && dx >= 0 && !check[dx][dy] && vegetablearray[dx][dy] == 1)
			dfs(dx, dy);
	}
	
}
void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && vegetablearray[i][j] == 1) {
				answer++;
				dfs(i, j);
			}
		}
	}
}

int main(void) {
	int t,k,x,y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		initarray(); 
		initcheck();
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			vegetablearray[y][x] = 1;
		}
		search();
		cout << answer << "\n";
		answer = 0;
	}
}