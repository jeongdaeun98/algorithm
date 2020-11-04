//8진수 2진수
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    string eightVerse, twoVerse= "";
    cin >> eightVerse;
    for(int i = 0; i < eightVerse.size(); i++){
        int num = eightVerse[i] - '0';
        string parseTwoVerse = "";
        while(num > 1){
            parseTwoVerse += to_string(num % 2);
            num /= 2;
        }
        parseTwoVerse += to_string(num);
        while(parseTwoVerse.size() != 3){
            parseTwoVerse += "0";
        }
        reverse(parseTwoVerse.begin(), parseTwoVerse.end());
        twoVerse += parseTwoVerse;
    }
    for(int i = 0; i < twoVerse.size();){
        if(twoVerse[i] != '0'){
            break;
        }
        twoVerse.erase(twoVerse.begin());
    }
    if(twoVerse.empty()) cout << "0";
    else cout << twoVerse;
}