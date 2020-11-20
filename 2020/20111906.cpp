#include <iostream>
#include <string>
using namespace std;

int main(void){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        string bracket;
        cin >> bracket;
        int openOne = 0,openTwo = 0;
        int answer = 0;
        for(int j = 0; j < bracket.size(); j++){
            if(bracket[j] == '('){
                openOne++;
            }
            if(bracket[j] == '['){
                openTwo++;
            }
            if(openOne > 0 && bracket[j] == ')'){
                answer++;
                openOne--;
            }
            if(openTwo > 0 && bracket[j] == ']'){
                answer++;
                openTwo--;
            }
        }
        cout << answer << "\n";
    }
}
