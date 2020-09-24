#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> ball;
int visited[10] = { 0 };
int answer = 0;
bool trueball(string sum) {
	for (int i = 0; i < ball.size(); i++) {
		int strike = 0;
		int fail = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (sum[j] == to_string(ball[i][0])[k] && j == k)
					strike++;
				else if (sum[j] == to_string(ball[i][0])[k] && j != k)
					fail++;
			}
			
		}
		if (strike != ball[i][1]) return false;
		if (fail != ball[i][2]) return false;
	}
	return true;
}
void dfs(int depth, string sum) {
	if (depth == 3) {
		if (trueball(sum)) answer++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(depth + 1, sum + to_string(i));
		visited[i] = 0;
	}
}

int solution(vector<vector<int>> baseball) {
	ball = baseball;
	dfs(0, "");
	return answer;
}