#include <iostream>
#include <vector>
using namespace std;

long long gcdSum = 0;
int uclid(int a, int b){
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    while(a % b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}
void combination(int count, vector<int> number, vector<int> realNum, int index){
    if(count == 0){
        int gcd = uclid(number[0], number[1]);
        gcdSum += gcd;
        return;
    }
    else if(index == realNum.size()) return;
    number.push_back(realNum[index]);
    combination(count- 1, number, realNum, index + 1);
    number.pop_back();
    combination(count, number, realNum, index + 1);
}
int main(void){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int count;
        cin >> count;
        vector<int> number;
        while(count--){
            int num;
            cin >> num;
            number.push_back(num);
        }
        vector<int> combNumberVector;
        combination(2, combNumberVector, number, 0);
        
        cout << gcdSum << "\n";
        gcdSum = 0;
    }

}