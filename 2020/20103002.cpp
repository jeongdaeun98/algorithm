//집합
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count, num;
    int number[21] = {0};
    cin >> count;
    for(int i = 0; i < count; i++){
        string str;
        cin >> str;
        if(!str.compare("add")){
            cin >> num;
            number[num] = 1;
        }
        else if(!str.compare("remove")){
            cin >> num;
            number[num] = 0;
        }
        else if(!str.compare("check")){
            cin >> num;
            if(number[num] == 1)
                cout << 1 << "\n";
            else
            cout << 0 << "\n";
            
        }
        else if(!str.compare("toggle")){
            cin >> num;
            if(number[num] == 1){
                number[num] = 0;
            }
            else{
                number[num] = 1;
            }
        }
        else if(!str.compare("all")){
            for(int i = 1; i < 21; i++){
                number[i] = 1;
            }
        }
        else if(!str.compare("empty")){
            for(int i = 1; i < 21; i++){
                number[i] = 0;
            }
        }
    }
}