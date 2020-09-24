#include<iostream>
#include<vector>
using namespace std;
int numbersize,*num;
vector<int> number;
void initNum() {
	num = new int[numbersize];
	for (int i = 0; i < numbersize; i++)
		cin >> num[i];
}
void combination(int numsize,int index) {
	if (6 == numsize) {
		int size = number.size();
		for (int i = 0; i < size; i++) {
			cout << number[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = index; i < numbersize; i++) {
			number.push_back(num[i]);
			combination(numsize + 1,i + 1);
			number.pop_back();
		}
	}
}
int main(void) {
	while (1) {
		cin >> numbersize;
		if (numbersize == 0) break;
		else {
			initNum();
			combination(0,0);
			cout << "\n";
		}
	}
}