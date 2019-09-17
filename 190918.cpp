#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = number; int erasenum = 0, size; bool sorttrue = false;
	while (erasenum != k) {
		size = answer.size();
		for (int i = 0; i < size - 1; i++) {
			if (answer[i] < answer[i + 1]) {
				answer.erase(answer.begin() + i);
				sorttrue = true;
				break;
			}
		}
		if (!sorttrue)
			answer.erase(answer.end() - 1);
		sorttrue = false;
		erasenum++;
	}
	return answer;
}