#include <string>
#include <iostream>
using namespace std;
int n, m;
void permutate(bool check[], string num,int placenum) {
	if (placenum == m) {
		cout << num << "\n";
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				check[i] = true;
				num.append(to_string(i + 1)+" ");
				permutate(check, num, placenum + 1);
				num.pop_back(); num.pop_back();
				check[i] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	bool check[8] = { false, };
	int placenum = 0;
	string num = "";
	permutate(check,num,placenum);

}