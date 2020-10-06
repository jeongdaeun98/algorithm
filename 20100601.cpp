#include <vector>
#include <unordered_map>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, bool> socksHash;
    int answer = 0;
    for(int i = 0; i < n; i++){
        unordered_map<int, bool>:: iterator socksIter = socksHash.find(ar[i]);
        if(socksIter != socksHash.end()){
            socksHash.erase(socksIter);
            answer++;
        }
        else{
            socksHash.insert(make_pair(ar[i], true));
        }
    }
    return answer;

}