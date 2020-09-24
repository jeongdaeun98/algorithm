#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	ans.push_back(v[0][0] ^ v[1][0] ^ v[2][0]);
	ans.push_back(v[0][1] ^ v[1][1] ^ v[2][1]);
	return ans;
}