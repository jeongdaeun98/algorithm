#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> clothMap;
	for (int i = 0; i < clothes.size(); i++) 
		clothMap[clothes[i][1]]++;
	
	for (unordered_map<string, int> ::iterator clothIter = clothMap.begin(); clothIter != clothMap.end(); ++clothIter)
		answer *= (clothIter->second + 1);
	return answer - 1;
}