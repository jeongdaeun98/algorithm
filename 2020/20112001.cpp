#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
int t;
cin >> t;
while(t --){
    long long sum = 0, n = 0, m = 0, a = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        m = max(m, a);
    }
    if(sum >= (n - 1) * m){
        if( sum % (n - 1) * m == 0) cout << 0 << "\n";
        else cout << (n - 1) - (sum % (n - 1)) << "\n";
    }else{
        cout << (n - 1) * m - sum << "\n";
    }
}
}