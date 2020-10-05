#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) 
{
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimiter)) 
	{
		internal.push_back(temp);
	}
	return internal;
}

vector<string> solution(vector<string> rooms, int target) {
    vector<string> answer;
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    unordered_map<string, bool> roomHash;
    for(int i = 0; i < rooms.size(); i++){
        vector<string> splittedVector = split(rooms[i], ']');
        splittedVector[0].erase(splittedVector[0][1]);
        int roomNumber = stoi(splittedVector[0]);
        vector<string> nameVector = split(splittedVector[1], ',');
        if(target == roomNumber){
            for(int j = 0; j < nameVector.size(); j++){
                roomHash.insert(make_pair(nameVector[j], true));
            }
        }
        else{
            for(int j = 0; j < nameVector.size(); j++){
                if(roomHash.find(nameVector[j]) == roomHash.end()){
                    pq.push(make_pair(abs(roomNumber - target), nameVector[j]));
                }
            }
        }
    }
    while(!pq.empty()){
        if(roomHash.find(pq.top().second) == roomHash.end()){
            answer.push_back(pq.top().second);
        }
        pq.pop();
    }
    return answer;
}