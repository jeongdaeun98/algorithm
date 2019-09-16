#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int **check;
string *apartment;
int num, estatenum = 0, directoryX[] = { 0,0,1,-1 }, directoryY[] = { 1,-1,0,0 };
vector <int> estate;
void initcheck() {
	check = new int*[num];
	for (int i = 0; i < num; i++)
		check[i] = new int[num];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			check[i][j] = false;
		}
	}
}
void initApartment() {
	apartment = new string[num];
	for (int i = 0; i < num; i++) {
		cin >> apartment[i];
	}
}
void printEstate() {
	sort(estate.begin(), estate.end());
	int size = estate.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++)
		cout << estate[i] << "\n";
}
void dfs(int x, int y) {
	estatenum++;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + directoryX[i];
		int dy = y + directoryY[i];
		if (dx >= 0 && dx < num && dy >= 0 && dy < num && !check[dx][dy] && apartment[dx][dy] == '1') 
			dfs(dx, dy);
		
	}
}
void searchEstate() {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (!check[i][j] && apartment[i][j] == '1') {
				estatenum = 0;
				dfs(i, j);
				estate.push_back(estatenum);
			}
		}
	}
}
int main(void) {
	cin >> num;
	initcheck();
	initApartment();
	searchEstate();
	printEstate();
}