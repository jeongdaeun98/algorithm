#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> swap(vector<int> array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    return array;
}
bool compare(int a, int b){
    return a > b;
}
int main(void){
    int count;
    bool isBefore = false;
    cin >> count;
    vector<int> array;
    for(int i = 0; i < count; i++){
        int num;
        cin >> num;
        array.push_back(num);
    }
    for(int i = count - 1; i > 0; i--){
        if(array[i - 1] > array[i]){
            isBefore = true;
            for(int j = count - 1; j > i - 1; j--){
                if(array[i - 1] > array[j]){
                    array = swap(array,i - 1, j);
                    break;
                }
            }
            sort(array.begin() + i, array.end(), compare);
            break;
        }
    }
    if(!isBefore) cout << - 1;
    else{
        for(int i = 0; i < count; i++){
            cout << array[i] << " ";
        }
    }
    
}