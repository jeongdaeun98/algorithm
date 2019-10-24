#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	bool pass = true;
	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				answer.push_back(j - i);
				pass = false;
				break;
			}
		}
		if(pass) answer.push_back(prices.size() - 1 - i);
		pass = true;
	}
	return answer;
}