#include <iostream>
using namespace std;

int uclid(int a, int b){
    int temp;
    if(b > a){
        temp = a;
        a = b;
        b = temp;
    }
    while(a % b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}
int main(void){
    int count;
    cin >> count;
    while(count--){
        int a, b;
        cin >> a >> b;
        int gcd = uclid(a, b);
        int minCommonMultiple = gcd * (a/gcd) * (b/gcd);
        cout << minCommonMultiple << "\n";
    }
}