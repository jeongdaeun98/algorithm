#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int r, c,maxnum = 0;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
string board[20];
void dfs(int x, int y, vector<char> &alphabet, int cnt) {
	alphabet.push_back(board[x][y]);
	if (maxnum < cnt) maxnum = cnt;
	for (int i = 0; i < 4; i++) {
		int dx = directx[i] + x;
		int dy = directy[i] + y;
		if (dx < r && dx >= 0 && dy < c && dy >= 0  && find(alphabet.begin(), alphabet.end(), board[dx][dy]) == alphabet.end()) {
			dfs(dx, dy, alphabet,cnt+1);
			alphabet.pop_back();
		}
	}
	
}
int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; i++) 
		cin >> board[i];
	vector<char>alphabet;
	dfs(0,0,alphabet,1);
	cout << maxnum;
}