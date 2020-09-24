#include <iostream>
#include <vector>
using namespace std;
int **area,n,safezoneNum = 0,maxnum = 0;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
bool **check;
void initCheck() {
	check = new bool *[n];
	for (int i = 0; i < n; i++)
		check[i] = new bool[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			check[i][j] = false;
	}
}
void initArea() {
	cin >> n;
	area = new int *[n];
	for (int i = 0; i < n; i++)
		area[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> area[i][j];
	}
}
void dfs(int x, int y,int num) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + directx[i];
		int dy = y + directy[i];
		if (dx < n && dx >= 0 && dy < n && dy >= 0 && !check[dx][dy] && area[dx][dy] > num)
			dfs(dx, dy, num);
	}
}
void searchdfs(int num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(!check[i][j] && area[i][j] > num){
				safezoneNum++;
				dfs(i,j,num);
			}
		}
	}
}
int main(void) {
	initArea();
	initCheck();
	for (int i = 0; i < 100; i++) {
		searchdfs(i);
		if (safezoneNum == 0) break;
		if (maxnum < safezoneNum)
			maxnum = safezoneNum;
		safezoneNum = 0;
		initCheck();
	}
	cout << maxnum;

}