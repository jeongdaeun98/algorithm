#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareNum(pair<int,int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(void){
    int answer = 1;
    int testCase, start, end;
    cin >> testCase;
    vector<pair<int,int>> meetingRoom;
    
    for(int i = 0; i < testCase; i++){
        cin >> start >> end;
        meetingRoom.push_back({start, end});
    }
    sort(meetingRoom.begin(), meetingRoom.end(), compareNum);
    int startTime = meetingRoom[0].second;
    for(int i = 1; i < testCase; i++){
        if(meetingRoom[i].first >= startTime){
            answer++;
            startTime = meetingRoom[i].second;
        }
    }
    cout << answer;
}