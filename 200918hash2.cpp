#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Compare{
public:
    bool operator() (pair<int, int> lhs, pair<int, int> rhs){
        if (lhs.first == rhs.first;
    }
};
 
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> musicQ;
    unordered_map<string, vector<int>> genreMap;
    unordered_map<string, int> sortingGenreMap;
    priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> genreQ;
    for(int i = 0; i < plays.size(); i++){
        unordered_map<string, int>::iterator sortingGenreMapIterator = sortingGenreMap.find(genres[i]);
        if(sortingGenreMapIterator != sortingGenreMap.end()) {
            int playNum = sortingGenreMapIterator->second;
            sortingGenreMap.erase(genres[i]);
            sortingGenreMap.insert(make_pair(genres[i], playNum + plays[i]));
        }
        else {
            sortingGenreMap.insert(make_pair(genres[i], plays[i]));
        }
    }
    for(pair<string, int> sortingGenre : sortingGenreMap){
        genreQ.push(make_pair(sortingGenre.second, sortingGenre.first));
    }
    for(int i = 0; i < plays.size(); i++) {
        musicQ.push(make_pair(plays[i], i));
    }
    while(!musicQ.empty()) {
        string genre = genres[musicQ.top().second];
        unordered_map<string, vector<int>>::iterator genreMapIterator = genreMap.find(genre);
        if(genreMapIterator != genreMap.end() && genreMapIterator->second.size() != 2){
            vector<int> valueVector = genreMapIterator->second;
            valueVector.push_back(musicQ.top().second);
            genreMap.erase(genre);
            genreMap.insert(make_pair(genre,valueVector));
        }
        else if(genreMapIterator == genreMap.end()) {
            vector<int> valueVector;
            valueVector.push_back(musicQ.top().second);
            genreMap.insert(make_pair(genre,valueVector));
        }
        musicQ.pop();
    }
    while(!genreQ.empty()) {
        vector<int> genreMusicVector = genreMap.find(genreQ.top().second)->second;
        answer.insert(answer.end(),genreMusicVector.begin(), genreMusicVector.end());
        genreQ.pop();
    }
    return answer;
}