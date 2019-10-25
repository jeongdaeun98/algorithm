#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	priority_queue<pair<int, int>> pq;
	unordered_map<string, int>music;
	unordered_map<string,int> result;
	for (int i = 0; i < genres.size();i++) {
		unordered_map<string, int> ::iterator it = music.find(genres[i]);
		if (it != music.end()) {
			int sum = plays[i]+ it->second;
			music.erase(it);
			music.insert(make_pair(genres[i], sum));
		}
		else
			music.insert(make_pair(genres[i], plays[i]));
	}

	for (int i = 0; i < genres.size(); i++) {
		unordered_map<string, int> ::iterator it = music.find(genres[i]);
		plays[i] = plays[i] + it->second;
		pq.push(make_pair(plays[i], i));
	}
	while (!pq.empty()) {
		pair<int,int> node = pq.top();
		unordered_map<string, int> ::iterator it = result.find(genres[node.second]);
		if (it != result.end() && it->second != 2) {
			result.erase(it);
			result.insert(make_pair(genres[node.second],2));
			answer.push_back(node.second);
		}
		else if (it == result.end()) {
			result.insert(make_pair(genres[node.second], 1));
				pq.pop();
			if (!pq.empty()&&pq.top().first == node.first && genres[node.second] == genres[pq.top().second]) {
				answer.push_back(pq.top().second);
				answer.push_back(node.second);
			}
			else if(!pq.empty()&&genres[node.second] == genres[pq.top().second]) {
				result.erase(it);
				result.insert(make_pair(genres[node.second], 2));
				answer.push_back(node.second);
				answer.push_back(pq.top().second);
			}
				
		}
		if (!pq.empty())
		pq.pop();
	}
	return answer;
}