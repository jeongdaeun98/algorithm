//팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main(void){
    long long n, zeroCount = 0;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        long long num = i;
        if(num % 5 == 0){
            while(num % 5 == 0){
                num /= 5;
                zeroCount++;
            }
        }
    }
    cout << zeroCount;
}
