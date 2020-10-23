#include <vector>
#include <algorithm>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
     vector<int> answer;
    for(int i = d -1; i >= 0; i--){
        answer.push_back(a[i]);
    }
    for(int i = a.size() - 1; i >= d; i--){
        answer.push_back(a[i]);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}