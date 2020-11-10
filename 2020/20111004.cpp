//카잉 달력
#include <iostream>
using namespace std;

int uclid(int a, int b){
    while(a % b != 0){
        int n = a % b;
        a = b;
        b = n;
    }
    return b;
}

int main(void){
    int test;
    cin >> test;
    while(test--){
        bool isPossible = false;
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        int gcd = uclid(m, n);
        int divideM = m / gcd;
        int divideN = n / gcd;
        for(int i = 0; (i*m+x) <= gcd * divideM * divideN; i++){
            if((i*m+x) % n == y || ((i*m+x) % n == 0 && y == n) ){
                cout << i*m + x << "\n";
                isPossible = true;
                break;
            }
        }
        if(!isPossible) cout << -1 << "\n";
    }
}