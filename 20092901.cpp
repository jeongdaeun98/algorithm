#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
vector<int> solution(vector<string> &S) {
    unordered_map<pair<int,int>,int,pair_hash> sameThingMap;
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S[i].size(); j++){
            unordered_map<pair<int,int>,int,pair_hash>::iterator sameThingMapIterator = sameThingMap.find(make_pair(S[i][j],j));
            if(sameThingMapIterator != sameThingMap.end()){
                    vector<int> answer;
                    answer.push_back(sameThingMapIterator->second);
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
            }
            sameThingMap.insert(make_pair(make_pair(S[i][j],j),i));
        }
    }
}
