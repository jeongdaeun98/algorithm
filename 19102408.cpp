#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	for (double i = 1; i <= red; i++) {
		double temp = red / i;
		if (temp == floor(temp)) {
			if ((temp + 2) * (i + 2) - red == brown) {
				if (temp >= i) {
					answer.push_back(temp + 2);
					answer.push_back(i + 2);
					break;
				}
				else {
					answer.push_back(i + 2);
					answer.push_back(temp + 2);
					break;
				}
			}
		}
	}
	return answer;
}