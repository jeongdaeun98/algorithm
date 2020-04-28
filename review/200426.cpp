#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;
int makesFruitBox(int fruit[], int fruitNum){
    int fruitBox = -1000000, miniBox = 0;
     for(int i = 0; i < fruitNum; i++) {
        miniBox = max(0, miniBox) + fruit[i];
        fruitBox = max(miniBox, fruitBox); 
    } 
    return fruitBox;
}
int main() {
    int fruitNum, fruit[100000];
    cin >> fruitNum;

    for(int i = 0; i < fruitNum; i++){
        cin >> fruit[i];
    }
     cout << makesFruitBox(fruit, fruitNum);
}