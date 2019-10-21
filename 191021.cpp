#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string name;
	int num[26] = {0};
	cin >> name;
	for (int i = 0; i < name.size(); i++)
		num[name[i] - 'a'] += 1;
	for (int i = 0; i < 26; i++)
		cout << num[i] << " ";
}