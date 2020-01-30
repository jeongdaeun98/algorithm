#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	
	char alphabet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int number[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	string input;

	getline(cin,input);
	int i= 0,j,sum = 0;
	int length = input.length();
	int len = strlen(alphabet);
	while (true) {
		if (i == length) break;
		for (j = 0; j < len; j++) {
			if (input.at(i) == alphabet[j])
				sum = sum + 1 + number[j];
		}
		i++;
	}
	cout << sum;
}