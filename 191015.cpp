#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n,kim,lim,answer = 0;
	bool endTrue = false;
	vector<int> num;
	cin >> n>>kim>>lim;
	for (int i = 0; i < n; i++) {
		num.push_back(i + 1);
	}
	while (1) {
		if (endTrue || num.size() == 0) break;
		answer++;
		for (int i = 0; i < num.size() - 1; i++) {
			int remove = i;
			if ((num[i] == kim || num[i] == lim) && (num[i + 1] == lim || num[i + 1] == kim)) {
				endTrue = true;
				break;
			}
			if (num[i] == kim || num[i] == lim)
				remove = i + 1;
			num.erase(num.begin() + remove);
		}
	}
	if (endTrue) cout << answer;
	else cout << -1;
}