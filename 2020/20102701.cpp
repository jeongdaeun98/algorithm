#include <iostream>
using namespace std;

int main(void){
    int a, b, copyA, copyB;
    cin >> a >> b;
    int maxCommonFactor = 1;
    int minCommonMultiple = 1;
    copyA = a, copyB = b;
    if(a > b){
        while(a%b != 0){
            int temp = a % b;
            a = b;
            b = temp;
        }
        maxCommonFactor = b;
    }
    else {
        while(b%a != 0){
            int temp = b % a;
            b = a;
            a = temp;
        }
        maxCommonFactor = a;
    }
    minCommonMultiple = copyA/maxCommonFactor * copyB/maxCommonFactor * maxCommonFactor;
    cout << maxCommonFactor << "\n" << minCommonMultiple; 
}