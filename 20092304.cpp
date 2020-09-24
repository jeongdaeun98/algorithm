#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number.substr(k);
    for(int i = k - 1; i>= 0; i--){
        int j = 0;
        do{
            if(number[i] >= answer[j]){
                int temp = number[i];
                number[i] = answer[j];
                answer[j] = temp;
                j++;
            }else {
                break;
            }
        }while(1);
    }
    return answer;
}