#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = A.size() - 1; i >= 0; i--) {
		int left = 0, right = B.size() - 1,mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (A[i] < B[mid]) {
				A.erase(A.begin() + i);
				B.erase(B.begin() + mid);
				answer++;
				break;
			}
			else
				left = mid + 1;
		}
	}
	return answer;
}