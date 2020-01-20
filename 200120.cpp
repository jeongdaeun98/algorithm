#include <cstdio>
#define VALUE 1000000009
#define SIZE 1000001
using namespace std;

int main(void) {
	long long num[SIZE], number,t;
	num[1] = 1; num[2] = 2; num[3] = 4;
	for (int i = 4; i < SIZE; i++)
		num[i] = ((num[i - 1] + num[i - 2] + num[i - 3])) % VALUE;
	scanf_s("%lld", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%lld", &number);
		printf("%lld\n", num[number]);
	}
}