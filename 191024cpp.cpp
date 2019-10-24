#include <string>
#include <vector>

using namespace std;
string answer = "";
void trasition(int n ) {
	char c[] = { '4','1','2' };
	n = n / 3;
	if (n > 0) trasition(n);
	answer += c[n % 3];
}

string solution(int n) {
	
	trasition(n);
	return answer;
}