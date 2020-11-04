//진법 변환 2
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int tenNum, b;
    cin >> tenNum >> b;
    string bNum;
    while(tenNum >= b){
        if(tenNum % b >= 10){
            bNum += (tenNum % b) - 10 + 'A';
        }
        else{
            bNum += (tenNum % b) + '0';
        }
        tenNum /= b;
    }
    if(tenNum >= 10){
            bNum += (tenNum) - 10 + 'A';
        }
        else{
            bNum += (tenNum) + '0';
        }
    reverse(bNum.begin(), bNum.end());
    cout << bNum;
}