#include <string>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long answer = 0;
    long aSize = n/s.size();
    long aCount = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            aCount++;
        }
    }
    answer = aCount * aSize;
    for(int i = 0; i < n%s.size(); i++){
        if(s[i] == 'a'){
            answer++;
        }
    }
    return answer;
}
