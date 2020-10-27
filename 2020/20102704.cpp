#include <iostream>
#define EARTH_NUM 15
#define SUN_NUM 28
#define MOON_NUM 19
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int earth, sun, moon, num = 1;
    cin >> earth >> sun >> moon;
    while(1){
    int earthDay = (num - earth) % EARTH_NUM;
    int sunDay = (num - sun) % SUN_NUM;
    int moonDay = (num - moon) % MOON_NUM;
    if(0 == earthDay && 0 == sunDay && 0 == moonDay)
    break;
    num++;
    }
    cout << num;
}