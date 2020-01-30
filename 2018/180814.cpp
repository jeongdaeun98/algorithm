#include <iostream>
using namespace std;
int main(void) {
	int firstmoney[7] = { 0,500,300,200,50,30,10 };
	int firstperson[7] = { 0,1,3,6,10,15,21};
	int secondmoney[6] = { 0,512,256,128,64,32 };
	int secondperson[6] = { 0,1,3,7,15,31 };
	int n,i,j;
	cin >> n;
	int *first = new int[n], *second = new int[n], *sum = new int[n];
	for (i = 0; i < n; i++) {
		sum[i] = 0;
		cin >> first[i];
		cin >> second[i];
	}
	for(i = 0; i < n; i++){
		for (j = 1; j < 7; j++) {
			if (firstperson[j] >= first[i] && firstperson[j - 1] < first[i]) {
				sum[i] += firstmoney[j];
				break;
			}
		}

		for (j = 1; j < 6; j++) {
			if (secondperson[j] >= second[i] && secondperson[j - 1] < second[i]) {
				sum[i] += secondmoney[j];
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		
		cout << sum[i]*10000;
		cout << "\n";
	}
	

}