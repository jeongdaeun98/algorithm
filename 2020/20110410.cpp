//진법 변환
#include <iostream>
#include <ctype.h>
#include <algorithm>
using namespace std;

int changeTenVerseNum(int digit, int num, int verse){
    int verseNum = 1;
    while(digit--){
        verseNum *= verse;
    }
    return num * verseNum;
}
int changeAlphaToNum(char alpha){
    return alpha - 'A' + 10;
}
int main(void){
    string bNum;
    int b, tenVerseNum = 0;
    cin >> bNum >> b;
    if(b == 10){ 
        cout << bNum;
        return 0;
    }
    reverse(bNum.begin(), bNum.end());
    if(b > 10){
        for(int i = 0; i < bNum.size(); i++){
            if(isupper(bNum[i])){
                tenVerseNum += changeTenVerseNum(i,changeAlphaToNum(bNum[i]), b);
            }
            else{
                tenVerseNum += changeTenVerseNum(i, bNum[i] - '0', b);
            }
        }
    }
    else{
        for(int i = 0; i < bNum.size(); i++){
            tenVerseNum += changeTenVerseNum(i, bNum[i] - '0', b);
        }
    }
    cout << tenVerseNum;
}