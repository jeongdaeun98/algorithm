#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimiter)){
		internal.push_back(temp);
	}
	return internal;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int, vector<int>, less<int>> maxpq;
    int count = 0,removedCount = 0;
    for(int i = 0; i < operations.size(); i++){
        vector<string> splittedOperations = split(operations[i], ' ');
        if(splittedOperations[0].compare("I") == 0){
            count++;
            minpq.push(stoi(splittedOperations[1]));
            maxpq.push(stoi(splittedOperations[1]));
        }
        else if(splittedOperations[0].compare("D") == 0 && stoi(splittedOperations[1]) == 1 && count - removedCount > 0){
            maxpq.pop();
            removedCount++;
        }
        else if(splittedOperations[0].compare("D") == 0 && stoi(splittedOperations[1]) == -1 && count - removedCount > 0){
            minpq.pop();
            removedCount++;
        }
        if(count - removedCount == 0){
            while(!minpq.empty()) minpq.pop();
            while(!maxpq.empty()) maxpq.pop();
        }
    }
    if(count - removedCount > 0){
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}