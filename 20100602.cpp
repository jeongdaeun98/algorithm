#include <string>
using namespace std;
int countingValleys(int steps, string path) {
    int answer = 0;
    int height = 0;
     bool oneLevelDown = false;
    for(int i = 0; i < steps; i++){
        if(path[i] == 'U'){
            height++;
        }
        else if(path[i] == 'D'){
            height--;
        }
        if(height == -1){
            oneLevelDown = true;
        }
        else if(height == 0 && oneLevelDown){
            answer ++;
            oneLevelDown = false;
        }
    }
    return answer;
}