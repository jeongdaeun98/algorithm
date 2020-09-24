#include <string>
#include <vector>
#include <queue>
using namespace std;
string skillstr;
string searchSkill(string order) {
	string returnstring = "";
	for (int i = 0; i < order.size(); i++) {
		for (int j = 0; j < skillstr.size(); j++) {
			if (order[i] == skillstr[j])
				returnstring.push_back(order[i]);
		}
	}
	return returnstring;
}
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	skillstr = skill;
	string order; 
	bool answertrue = true;
	for (int i = 0; i < skill_trees.size(); i++) {
		order = searchSkill(skill_trees[i]);
		for (int j = 0; j < order.size(); j++)
			if (skill[j] != order[j]) answertrue = false;
		if (answertrue)answer++;
		answertrue = true;
	}
	return answer;
}