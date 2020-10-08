#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int size, size2,number;
    scanf("%d", &size);
    vector<int> a(size);
    for(int i = 0; i < size; i++){
        scanf("%d", &number);
        a[i] = number;
    }
    sort(a.begin(), a.end());
    scanf("%d", &size2);
    for(int i = 0; i < size2; i++){
        int num;
        bool isNum = false;
        int left = 0, right = size - 1;
        scanf("%d", &num);
        while(left <= right){
            int mid = (left + right) /2;
            if(a[mid] > num){
                right = mid - 1;
            }
            else if(a[mid] < num){
                left = mid + 1;
            }
            else {
                printf("%d\n", 1);
                isNum = true;
                break;
            }
        }
        if(!isNum) printf("%d\n", 0);
    }
}