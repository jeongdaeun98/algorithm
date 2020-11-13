//스타트와 링크
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int score[20][20];
int n;
int answer = 987654321;
vector<int> start;
vector<int> link;
void permutation(int index){
    if(index == n){
        if(start.size() ==n / 2 && link.size() == n / 2){
        int sum = 0;
        for(int i = 0; i < start.size() - 1; i++){
            for(int j = i + 1; j < start.size(); j++){
                if(i == j) continue;
                sum += score[start[i]][start[j]] + score[start[j]][start[i]];
                sum -= score[link[i]][link[j]] + score[link[j]][link[i]];
            }
        }
        answer = min(answer, abs(sum));
        }
        return;
    }
    start.push_back(index);
    permutation(index + 1);
    start.pop_back();
    link.push_back(index);
    permutation(index + 1);
    link.pop_back();
}
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> score[i][j];
        }
    }
    permutation(0);
    cout << answer;
}