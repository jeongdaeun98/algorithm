#include <vector>
#include <math.h>
using namespace std;
int answer = 0;
bool isprime(int sum) {
	for (int i = 2; i <= sqrt(sum); i++) {
		if (sum % i == 0)
			return false;
	}
	return true;
}
void dfs(int depth, int index, vector<int>& nums,int sum,bool visited[]) {
	if (depth == 3) {
		if (isprime(sum))
			answer++;
		return;
	}
	for (int i = index; i < nums.size(); i++) {
		visited[i] = true;
		dfs(depth + 1, i + 1, nums, sum + nums[i],visited);
	}
}

int solution(vector<int> nums) {
	bool *visited = new bool[nums.size()];
	for (int i = 0; i < nums.size(); i++)
		visited[i] = false;
	dfs(0, 0, nums, 0, visited);
	return answer;
}