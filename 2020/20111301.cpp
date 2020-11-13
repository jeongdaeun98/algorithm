//소인수분해
#include <iostream>
using namespace std;

int main(void){
    int n, k = 2;
    cin >> n;
    while(n != 1){
        if(n % k == 0){
            n = n / k;
            cout << k << "\n";
        }
        else{
            k ++;
        }
    }
}