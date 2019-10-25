#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end(), desc);
	for (int i = 0; i < people.size(); i++) {
		answer++;
		for (int j = people.size() - 1; j >= i + 1;) {
			if (limit - people[i] >= people[j]) {
				people.erase(people.begin() + j);
				break;
			}
			else
				break;
		}
	}
	return answer;
}