#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<string>> ticket;
vector<vector<string>> answervector;
bool *check;
void initcheck() {
	int size = ticket.size();
	check = new bool[size];
	for (int i = 0; i < size; i++)
		check[i] = false;
}
void dfs(vector<string> answer,string node,int depth) {
	answer.push_back(node);
	if (depth == ticket.size()) {
		answervector.push_back(answer);
		return;
	}
	for (int i = 0; i < ticket.size(); i++) {
		if (!check[i] && node == ticket[i][0]) {
			check[i] = true;
			dfs(answer, ticket[i][1], depth + 1);
			check[i] = false;
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	ticket = tickets;
	initcheck();
	dfs(answer, "ICN", 0);
	sort(answervector.begin(), answervector.end());
	return answervector[0];
}