//2진수 8진수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string twoVerse, eightVerse = "";
    cin >> twoVerse;
    while(twoVerse.size() % 3 != 0){
        twoVerse.insert(0,"0");
    }
    for(int i = twoVerse.size() - 1; i >= 2; i-=3){
        eightVerse += to_string(twoVerse[i] - '0' +  (twoVerse[i - 1] - '0')*2 + (twoVerse[i - 2] - '0')*4);
    }
    reverse(eightVerse.begin(),eightVerse.end());
    cout << eightVerse;
}