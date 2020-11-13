//단어 수학
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b){
    return a > b;
}
int main(void){
    int count;
    string str;
    vector<string> wordVector;
    int word[26] = {0,};
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> str;
        wordVector.push_back(str);
    }
    for(int i = 0; i < wordVector.size(); i++){
        int powNum = 1;
        for(int j = wordVector[i].size() - 1; j >= 0; j--){
            word[wordVector[i][j] - 'A'] += powNum;
            powNum *= 10;
        }
    }
    sort(word, word + 26, compare);
    int number = 9, answer = 0;
    for(int i = 0; i < 26; i++){
        if(word[i] == 0) continue;
        answer += word[i] * number;
        number--;
    }
    cout << answer;

}