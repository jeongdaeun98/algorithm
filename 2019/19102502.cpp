#include <iostream>
#include<vector>

using namespace std;

int minimum(int a, int b, int c) {
	if (a >= b && c >= b) return b;
	else if (b >= a && c >= a) return a;
	else if (a >= c && b >= c) return c;
	else if (a == b && b == c) return b;
}
int solution(vector<vector<int>> board)
{
	int answer = 0;
	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[0].size(); j++) {
			if (board[i][j] == 0) continue;
			board[i][j] = minimum(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1;
			if (answer < board[i][j]) answer = board[i][j];
		}
	}
	bool zerotrue = true;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++)
			if (board[i][j] == 1) zerotrue = false;
	}
	if (!zerotrue && answer == 0) return 1;
	return answer * answer;
}