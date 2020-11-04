//숨바꼭질 6
#include <iostream>
#include <vector>
using namespace std;

int uclid(int a, int b){
    while(a % b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}
int main(void){
    int n, s, num, gcd;
    vector<int> sisterVector;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> num;
        sisterVector.push_back(abs(num - s));
    }
    gcd = sisterVector[0];
    for(int i = 1; i < n; i++){
        gcd = uclid(gcd, sisterVector[i]);
    }
    cout << gcd;
}