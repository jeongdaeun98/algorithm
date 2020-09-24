#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), compare);
    int j = people.size() - 1;
    for(int i = 0; i <= j; i++){
        int boatLimit = 0;
        boatLimit += people[i];
        if(boatLimit + people[j] <= limit){
            boatLimit += people[j];
            j--;
        }
        answer++;
    }
    return answer;
}