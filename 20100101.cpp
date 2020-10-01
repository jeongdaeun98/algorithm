#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int descCompare(int a, int b){
    return a > b;
}
int main(void){
    vector<int> number(8), copyNum(8);
    bool descTrue = true;
    bool ascTrue = true;
    for(int i = 0; i < 8; i++){
        cin >> number[i];
        copyNum[i] = number[i];
    }
    sort(number.begin(), number.end());
    for(int i = 0; i < 8; i++){
        if(number[i] != copyNum[i]){
            ascTrue = false;
            break;
        }
    }
    if(!ascTrue){
        sort(number.begin(), number.end(),descCompare);
        for(int i = 0; i < 8; i++){
            if(number[i] != copyNum[i]){
                descTrue = false;
                break;
            }
        }
        if(!descTrue){
            cout << "mixed";
        }
        else{
            cout << "descending";
        }
    }
    else{
        cout << "ascending";
    }
}