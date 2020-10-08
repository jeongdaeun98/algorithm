#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    int n, result;
    cin >> n;
    int num = n / 5;
    while(num >= 0){
        int remainder = n - num * 5;
        if(remainder == 0){ 
            cout << num;
            return 0;
        }
        if(remainder / 3 > 0 && remainder % 3 == 0){
            result = num + remainder / 3;
            cout << result;
            return 0;
        }
        else {
            num --;
        }
    }
    cout << -1;
}