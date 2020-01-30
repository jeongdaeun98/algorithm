#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int size = completion.size();
	for (int i = 0; i < completion.size();) {
		if (completion[i] != participant[i]) {
			return participant[i];
		}
		}
}