#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> magazineHash;
    string s1;
    int i = s1.size();
    for(int i = 0; i < magazine.size(); i++){
        unordered_map<string, int>::iterator magazineHashIter = magazineHash.find(magazine[i]);
        if(magazineHashIter != magazineHash.end()){
            int count = magazineHashIter->second;
            magazineHash.erase(magazineHashIter);
            magazineHash.insert(make_pair(magazine[i], count + 1));
        }else{
            magazineHash.insert(make_pair(magazine[i], 1));
        }
    }
    for(int i = 0; i < note.size(); i++){
        unordered_map<string, int>::iterator magazineHashIter = magazineHash.find(note[i]);
        if(magazineHashIter!= magazineHash.end()){
            int count = magazineHashIter->second;
            if(count > 0){
                magazineHash.erase(magazineHashIter);
                magazineHash.insert(make_pair(note[i], count - 1));
            }else{
                cout << "No";
                return;
            }
        }
        else {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
