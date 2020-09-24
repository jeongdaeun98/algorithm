#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool sorting(vector<int> listOne, vector<int>listTwo){
    if(listOne[2] > listTwo[2]) return true;
    else return false;
}
string solution(int n, vector<vector<int>> delivery) {
    string answer = "";
    unordered_map<int,string> storeWhat;
    sort(delivery.begin(), delivery.end(), sorting);
    for(int i = 0; i < delivery.size(); i++){
        if(delivery[i][2] == 1){
            storeWhat.insert(make_pair(delivery[i][0], "O"));
            storeWhat.insert(make_pair(delivery[i][1], "O"));
        }
        else{
            unordered_map<int,string> :: iterator first  = storeWhat.find(delivery[i][0]);
            unordered_map<int,string> :: iterator second  = storeWhat.find(delivery[i][1]);
            if(first != storeWhat.end() && first->second == "O"){
                if(second != storeWhat.end()) storeWhat.erase(delivery[i][1]);
                storeWhat.insert(make_pair(delivery[i][1], "X"));
            }
            else if(second != storeWhat.end() && second->second == "O"){
                if(first != storeWhat.end()) storeWhat.erase(delivery[i][0]);
                storeWhat.insert(make_pair(delivery[i][0], "X"));
            }
            else if (second == storeWhat.end() && first == storeWhat.end()){
                 storeWhat.insert(make_pair(delivery[i][0], "?"));
            storeWhat.insert(make_pair(delivery[i][1], "?"));
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(storeWhat.find(i + 1) != storeWhat.end()){
            answer += storeWhat.find(i + 1)->second;
        }
        else answer += "?";
    }
    return answer;
}