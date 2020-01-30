#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	
	int num,i;
	cin >> num;
	char **str = new char *[num];
	int **length = new int*[num];
	for (i = 0; i < num; i++) {
		str[i] = new char[50];
		length[i] = new int[2];
	}

	for (i = 0; i < num; i++) {
		cin >> str[i];
		length[i][0] = strlen(str[i]);
		length[i][1] = i;
	}

	sort(length[0], (length + num)[0]);
	
	for (i = 0; i < num; i++) {
		int len;
		len = length[i][1];
		cout << str[len] << endl;
	}

	


}