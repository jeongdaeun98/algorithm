#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
void dfs(int target, int number, vector<int>numbers, int index){
    if(number == target && index == numbers.size()){
        answer++;
    }
    if(index == numbers.size()) return;
    dfs(target, number+numbers[index], numbers, index + 1);
    dfs(target, number-numbers[index], numbers, index + 1);
}
int solution(vector<int> numbers, int target) {
    dfs(target, 0, numbers,0);
    return answer;
}