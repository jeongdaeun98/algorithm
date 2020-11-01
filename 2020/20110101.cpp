// 빗물
#include <iostream>
using namespace std;

int main(void){
    int h,w,maxIndex = 0,num[501], maxNum = 0, total = 0;
    cin >> h >> w;
    for(int i = 0; i < w; i++){
        cin >> num[i];
        if(maxNum < num[i]){
            maxNum = num[i];
            maxIndex = i;
        }
    }
    maxNum = 0;
    for(int i = 0; i < maxIndex; i++){
        maxNum = max(maxNum, num[i]);
        total += maxNum - num[i];
    }
    maxNum = 0;
    for(int i = w - 1; i > maxIndex; i--){
        maxNum = max(maxNum, num[i]);
        total += maxNum - num[i];
    }
    cout << total;
}