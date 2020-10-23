#include <vector>
#include <unordered_map>
using namespace std;

vector<int> swap(int a, int b, vector<int> arr){
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return arr;
}
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int count = 0;
    unordered_map<int, int> arrHash;
    for(int i = 0; i < arr.size(); i++){
        arrHash.insert(make_pair(arr[i], i));
    }
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != i + 1){
            unordered_map<int, int> :: iterator arrHashIter = arrHash.find(i+1);
            int foundIndex = arrHashIter->second;
            arr = swap(i, foundIndex, arr);
            arrHash.erase(i+1);
            arrHash.erase(arr[foundIndex]);
            arrHash.insert(make_pair(i+1, i));
            arrHash.insert(make_pair(arr[foundIndex], foundIndex));
            count++;
        }
    }
    return count;
}
