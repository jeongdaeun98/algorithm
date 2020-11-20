#include <iostream>
using namespace std;
int main(void){
    int test, x, y;
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> x >> y;
        int plusNum = abs(x - y);
        if(plusNum > 1){
            cout << x + y + plusNum - 1 << "\n";
        }
        else {
            cout << x + y << "\n";
        }
    }
}