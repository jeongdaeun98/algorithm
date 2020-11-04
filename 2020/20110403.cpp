//조합 0의 개수
#include <iostream>
using namespace std;

long long countFive(long long num){
    int fiveCount = 0;
    for(long long i = 5; i <= num; i*=5){
        fiveCount += num / i;
    }
    return fiveCount;
}
long long countTwo(long long num){
    int twoCount = 0;
    for(long long i = 2; i <= num; i*=2){
        twoCount += num / i;
    }
    return twoCount;
}
int main(void){
    long long n,m;
    cin >> n >> m;
    cout << min(countFive(n) - countFive(m) - countFive(n - m)
    , countTwo(n) - countTwo(m) - countTwo(n - m));
}