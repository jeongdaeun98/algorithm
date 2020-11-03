//수 이어쓰기 1
#include <iostream>
#include <string>
using namespace std;

int getNumCount(int tenNum, int nineNum){
    return nineNum - tenNum + 1;
}
int main(void){
    string numStr;
    cin >> numStr;
    string tenStr= "1", nineStr = "9";
    int numLength = 0;
    for(int i = 0; i < numStr.size() - 1; i++){
        numLength += (getNumCount(stoi(tenStr), stoi(nineStr))) * tenStr.size();
        tenStr += "0";
        nineStr += "9";
    }
    numLength += (stoi(numStr) - stoi(tenStr) + 1) * tenStr.size();
    cout << numLength;
}