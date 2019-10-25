#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int a, int b){
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	int answer = 0;

	while (!q.empty()) {
		if (q.size() == (n / 2)) {
			answer++;
			n = n / 2;
		}
		int num1 = q.front();
		q.pop();
		int num2 = q.front();
		q.pop();
		if ((num1 == a && num2 == b) || (num1 == b && num2 == a))
			break;
		if (num1 == a || num1 == b)
			q.push(num1);
		else if (num2 == a || num2 == b)
			q.push(num2);
		else
			q.push(num1);
		}

	return answer+1;
}