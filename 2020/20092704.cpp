#include <iostream>
#include <string>

using namespace std;

int main(void){
    string stick;
    cin >> stick;
    int total = 0, stickCount = 0;
    for(int i = 0; i < stick.size(); i++){
        if( i != stick.size() - 1 && stick[i] == '(' && stick[i + 1] == ')'){
            total += stickCount;
            i++;
        }
        else if(stick[i] == '('){
            stickCount++;
        }
        else if(stick[i] == ')'){
            total += 1;
            stickCount--;
        }
    }
    cout << total;
}