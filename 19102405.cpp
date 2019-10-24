#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
	unordered_map<string, int> clothkindnum;
	int answer = 1;
	for (int i = 0; i < clothes.size(); i++) {
		unordered_map<string, int> ::iterator it = clothkindnum.find(clothes[i][1]);
		if (clothkindnum.find(clothes[i][1]) != clothkindnum.end()) {
			int num = it->second;
			clothkindnum.erase(it);
			clothkindnum.insert(make_pair(clothes[i][1], num + 1));
		}
		else
			clothkindnum.insert(make_pair(clothes[i][1], 1));
	}
	for (auto i : clothkindnum) {
		answer *= (i.second + 1);
	}
	return answer - 1;
}