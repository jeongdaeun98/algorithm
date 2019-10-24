#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	int onenum = 0;
	int onenum2 = 0;
	int num = n;
	while (num > 0) {
		if (num % 2 == 1) onenum++;
		num = num / 2;
	}
	while (1) {
		n++;
		num = n;
		if (onenum2 == onenum) { answer = num - 1; break; }
		onenum2 = 0;
		while (num > 0) {
			if (num % 2 == 1) onenum2++;
			num = num / 2;
		}
	}
	return answer;
}