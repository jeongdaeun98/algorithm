#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> solution;
    vector<pair<int,int>> personPair;
    int person[3][10] = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    int answer[3] = {0,0,0};
    for(int i = 0 ; i  < answers.size(); i++){
        if(person[0][i % 5] == answers[i]) answer[0]++;
        if(person[1][i%8] == answers[i]) answer[1]++;
        if(person[2][i%10] == answers[i]) answer[2]++;
    }
    personPair.push_back(make_pair(answer[0], 1));
    personPair.push_back(make_pair(answer[1], 2));
    personPair.push_back(make_pair(answer[2], 3));
    sort(personPair.begin(),personPair.end());
    solution.push_back(personPair[2].second);
    for(int i = 0; i < 2; i++){
        if(personPair[i].first == personPair[2].first)
            solution.push_back(personPair[i].second);
    }
    sort(solution.begin(),solution.end());
    return solution;
}