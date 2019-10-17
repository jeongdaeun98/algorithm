#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0,sum = 0;
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++) {
		sum += d[i];
		if (budget < sum) { answer = i; break; }
		else answer = i + 1;
	}
	return answer;
}