#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> beforeAnswerVector;
void swap(int i, int j){
    int temp = beforeAnswerVector[i];
    beforeAnswerVector[i] = beforeAnswerVector[j];
    beforeAnswerVector[j] = temp;
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        beforeAnswerVector.push_back(num);
    }
    bool isNext = false;
    for(int i = n - 1; i > 0; i--){
        if(beforeAnswerVector[i - 1] < beforeAnswerVector[i]){
            isNext = true;
            for(int j = n - 1; j >= i; j--){
                if(beforeAnswerVector[i - 1] < beforeAnswerVector[j]){
                    swap(i - 1, j);
                    break;
                }
            }
            sort(beforeAnswerVector.begin() + i, beforeAnswerVector.end());
            break;
        }
    }
    if(!isNext) cout << -1;
    else{
        for(int i = 0; i < n; i++){
            cout << beforeAnswerVector[i] << " ";
        }
    }
}