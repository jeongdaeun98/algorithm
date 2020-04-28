#include <string>
#include <vector>

using namespace std;
int answer = 0;
void makeNumber(int sum,vector<int> &numbers,int target,int index) {
	
	if (sum == target) { answer++;  return; }
	if (index == numbers.size()) return;
	numbers[index] *= 1;
	makeNumber(sum + numbers[index], numbers, target, index + 1);
	numbers[index] *= -1;
	makeNumber(sum + numbers[index], numbers, target, index + 1);
}
int solution(vector<int> numbers, int target) {
	makeNumber(0, numbers, target, 0);
	return answer;
}