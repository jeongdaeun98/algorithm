#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int max;
vector<string> columnCombinations;
bool *select;
void initSelect() {
	select = new bool[max];
	for (int i = 0; i < max; i++)
		select[i] = false;
}
void dfs(int index ,int size, int target,string word, vector<vector<string>> &relation) {
	if (size == target) {
		columnCombinations.push_back(word);
		return;
	}
	for (vector<string> row : relation){
		for (int i = 0; i < row.size(); i++) {
			if (select[i])continue;
			select[i] = true;
			dfs(index + 1, size + 1, target, word + row[i], relation);
			select[i] = false;
			dfs(index + 1, size, target, word, relation);
		}
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	max = relation.size();
		for(int i = 1; i <= relation[0].size(); i++){
			dfs(0,0, i, "",relation);
			unordered_map<string, bool> keyMap;
			for (int i = 0; i < columnCombinations.size(); i++) {
				if (keyMap.find(columnCombinations[i]) == keyMap.end())
					keyMap.insert(make_pair(columnCombinations[i], i));
				else {
					
				}
			}
			for (unordered_map<string, bool> ::iterator i = keyMap.begin(); i != keyMap.end(); i++) {
				if (i->second)answer++;
			}
			columnCombinations.clear();
		}
	}

	return answer;
}