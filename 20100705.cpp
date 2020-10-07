#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    sort(arr.begin(), arr.end());
    long answer = 0;
    unordered_map<long, long> countHash;
    long arrSize = arr.size();
    for(long i = 0; i < arrSize; i++){
        unordered_map<long, long>:: iterator countHashIter = countHash.find(arr[i]);
        if(countHashIter != countHash.end()){
            long count = countHashIter->second;
            countHash.erase(arr[i]);
            countHash.insert(make_pair(arr[i], count + 1));
        }
        else{
            countHash.insert(make_pair(arr[i], 1));
        }
    }
    for(long i = 0; i < arrSize; i++){
        bool nonCount = false;
        int twoCount = 2;
        long count = 1;
        unordered_map<long, long>:: iterator countArrHashIter = countHash.find(arr[i]);
        if(countArrHashIter != countHash.end()){
            count *= countArrHashIter->second;
            long num = arr[i];
            while(twoCount--){
                num = num * r;
                unordered_map<long, long>:: iterator countArrMultiHashIter = countHash.find(num);
                if(countArrMultiHashIter != countHash.end()){
                    count *= countArrMultiHashIter->second;
                }
                else{
                    nonCount = true;
                    break;
                } 
        }
        countHash.erase(arr[i]);
        if(!nonCount){
            answer += count;
        }
        }
    }
    return answer;
}
