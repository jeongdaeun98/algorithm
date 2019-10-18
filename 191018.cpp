#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	priority_queue<int> supplyq;

	int answer = 0, i = 0, day = 0;
	while (1) {
		stock--;
		day++;
		if (day == k) return answer;
		if (dates[i] == day) {
			supplyq.push(supplies[i]);
			i++;
		}
		if (stock == 0) {
			answer++;
			stock = supplyq.top();
			supplyq.pop();
		}
		if (day == k) return answer;
	}
}