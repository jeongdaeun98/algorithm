#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

<<<<<<< HEAD
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimiter)){
=======
vector<string> split(string str, char delimiter) 
{
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimiter)) 
	{
>>>>>>> fc90c931754af87303bf70e04f1b5677bcccf66b
		internal.push_back(temp);
	}
	return internal;
}

vector<string> solution(vector<string> rooms, int target) {
    vector<string> answer;
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
<<<<<<< HEAD
    unordered_map<string, bool> targetRoomHash;
    unordered_map<string, bool> basicRoomHash;
    for(int i = 0; i < rooms.size(); i++){
        rooms[i].erase('[');
        vector<string> splittedVector = split(rooms[i], ']');
        splittedVector.erase(splittedVector.begin() + 1);
=======
    unordered_map<string, bool> roomHash;
    for(int i = 0; i < rooms.size(); i++){
        vector<string> splittedVector = split(rooms[i], ']');
        splittedVector[0].erase(splittedVector[0][1]);
>>>>>>> fc90c931754af87303bf70e04f1b5677bcccf66b
        int roomNumber = stoi(splittedVector[0]);
        vector<string> nameVector = split(splittedVector[1], ',');
        if(target == roomNumber){
            for(int j = 0; j < nameVector.size(); j++){
<<<<<<< HEAD
                targetRoomHash.insert(make_pair(nameVector[j], true));
=======
                roomHash.insert(make_pair(nameVector[j], true));
>>>>>>> fc90c931754af87303bf70e04f1b5677bcccf66b
            }
        }
        else{
            for(int j = 0; j < nameVector.size(); j++){
<<<<<<< HEAD
                pq.push(make_pair(abs(roomNumber - target), nameVector[j]));
=======
                if(roomHash.find(nameVector[j]) == roomHash.end()){
                    pq.push(make_pair(abs(roomNumber - target), nameVector[j]));
                }
>>>>>>> fc90c931754af87303bf70e04f1b5677bcccf66b
            }
        }
    }
    while(!pq.empty()){
<<<<<<< HEAD
        string userName = pq.top().second;
        if(targetRoomHash.find(userName) == targetRoomHash.end()){
            if(basicRoomHash.find(userName) == basicRoomHash.end()){
                answer.push_back(userName);
                basicRoomHash.insert(make_pair(userName, true));
            }
=======
        if(roomHash.find(pq.top().second) == roomHash.end()){
            answer.push_back(pq.top().second);
>>>>>>> fc90c931754af87303bf70e04f1b5677bcccf66b
        }
        pq.pop();
    }
    return answer;
}