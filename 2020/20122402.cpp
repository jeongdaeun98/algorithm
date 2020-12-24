//톱니바퀴
#include <iostream>
using namespace std;

string saw[5];
int score[] = {0,1,2,4,8};
void rotateSaw(int sawNum, int rotation){
    if(rotation == -1){
        char firstNum = saw[sawNum][0];
        for(int i = 0; i < 7; i++){
            saw[sawNum][i] = saw[sawNum][i+1];
        }
        saw[sawNum][7] = firstNum;
    }
    else{
        char lastNum = saw[sawNum][7];
        for(int i = 6; i >= 0; i--){
            saw[sawNum][i + 1] = saw[sawNum][i];
        }
        saw[sawNum][0] = lastNum;
    }
}
void checkNeedRotationAndRotate(int sawNum, int rotation){
    if(sawNum == 1){
        int number = saw[1][2];
        rotateSaw(1,rotation);
        if(number != saw[2][6]){
            number = saw[2][2];
            rotateSaw(2, -1 * rotation);
            if(number != saw[3][6]){
                number = saw[3][2];
                rotateSaw(3, rotation);
                if(number != saw[4][6]){
                    rotateSaw(4, -1 *rotation);
                }
            }
        }
    }
    else if(sawNum == 2){
        int number = saw[2][6];
        int number2 = saw[2][2];
        rotateSaw(2, rotation);
        if(number != saw[1][2]){
            rotateSaw(1, -1 *rotation);
        }
        if(number2 != saw[3][6]){
            number = saw[3][2];
            rotateSaw(3, -1 * rotation);
            if(number != saw[4][6]){
                rotateSaw(4, rotation);
            }
        }
    }
    else if(sawNum == 3){
        int number = saw[3][6];
        int number2 = saw[3][2];
        rotateSaw(3,rotation);
        if(number2 != saw[4][6]){
            rotateSaw(4, -1 * rotation);
        }
        if(number != saw[2][2]){
            number = saw[2][6];
            rotateSaw(2, -1 * rotation);
            if(number != saw[1][2]){
                rotateSaw(1, rotation);
            }
        }
    }
    else{
        int number = saw[4][6];
        rotateSaw(4, rotation);
        if(number != saw[3][2]){
            number = saw[3][6];
            rotateSaw(3, -1 * rotation);
            if(number != saw[2][2]){
                number = saw[2][6];
                rotateSaw(2, rotation);
                if(number != saw[1][2]){
                    rotateSaw(1, -1 * rotation);
                }
            }
        }
    }
}
int getAnswer(){
    int answer = 0;
    for(int i = 1; i < 5; i++){
       answer += (saw[i][0] - '0') * score[i];
    }
    return answer;
}
int main(void){
    int count, sawNum, rotation;
    for(int i = 1; i < 5; i++){
        cin >> saw[i];
    }
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> sawNum >> rotation;   
        checkNeedRotationAndRotate(sawNum, rotation);
    }
    cout << getAnswer();
}