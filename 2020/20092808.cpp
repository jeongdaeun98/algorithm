#include <vector>
using namespace std;

vector<int> backward(vector<int> array){
    int j = 0;
    vector<int> copy = array;
    for(int i = copy.size() - 1; i >= 0; i--){
            array[j] = copy[i];
            j++;
    }
    return array;
}
vector<int> solution(vector<int> &A, int K) {
    if(A.size() == 0) return {};
    vector<int> array = A;
    while(K--){
        int j = 0;
        int final = array[array.size() - 1];
        vector<int> backwardVector = backward(array);
        backwardVector.erase(backwardVector.begin());
        backwardVector.push_back(final);
        array = backward(backwardVector);
    }
    return array;
}
