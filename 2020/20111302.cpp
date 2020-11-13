//base Conversion
#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int a, b, count, number;
	vector<int> num;

	cin>>a>>b;
	cin>>count;

	for(int i = 0; i < count; i++) {
        cin>>number;
        num.push_back(number);
    }

	int dec = 0; 
	for(int i = 0; i < count; i++){
        dec = dec * a + num[i];
    }

	vector<int> vec;
	while(dec != 0){
		vec.push_back(dec % b);
		dec = dec / b;
	}

	for(int i = vec.size() - 1; i >= 0; i--){
		cout<<vec[i];
		if(i != 0) cout<<' ';
	}
}