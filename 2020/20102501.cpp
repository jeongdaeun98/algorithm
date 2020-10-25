#include <iostream>
#include <math.h>

using namespace std;

int main(void){
	int answer = 0, count;
	cin >> count;
	int *num = new int[count];
	for(int i = 0; i < count; i++){
		cin >> num[i];
	}
	bool isPrimeNum = true;
	for(int i = 0; i < count; i++){
		for(int j = 2; j <= sqrt(num[i]); j++){
			if(num[i] % j == 0) isPrimeNum = false;
		}
		if(num[i] != 1 && isPrimeNum) answer++;
		isPrimeNum = true;
	}
	cout << answer;
}