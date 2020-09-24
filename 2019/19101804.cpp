#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0,base,upnum;
	while (1) {
		if (n == 1) { ans++; return; }
		ans += n % 2;
		n = n / 2;
	}

	return ans;
}