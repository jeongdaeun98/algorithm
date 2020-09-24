#include <vector>
using namespace std;

int solution(vector<int> cookie) {
	int answer = 0, number1, number2;
	int *sum = new int[cookie.size() + 1];
	for (int i = 0; i <= cookie.size(); i++)
		sum[i] = 0;

	for (int i = 0; i < cookie.size(); i++)
		sum[i + 1] = sum[i] + cookie[i];

	for (int m = 1; m < cookie.size(); m++) {
		number1 = sum[m];
		for (int j = m + 1; j <= cookie.size(); j++) {
			number2 = sum[j] - number1;
			if (number2 > number1 || answer >= number2) continue;
			for (int l = 0; l < m; l++) {
				if ((number1 - sum[l]) == number2) {
					if (answer < number2)
						answer = number2;
					break;
				}
			}
		}
	}
	return answer;
}