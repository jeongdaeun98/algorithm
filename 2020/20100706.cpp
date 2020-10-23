#include <vector>

using namespace std;

double getMedian(int moneyInDate[], int d){
    int count = 0;
    double median;
    if(d % 2 != 0){
        for(int i = 0; i <= 200; i++){
            count += moneyInDate[i];
            if(count > d / 2){
                median = i;
                break;
            }
        }
    }
    else{
        int firstData = 0, secondData = 0;
        for(int i = 0; i <= 200; i++){
            count += moneyInDate[i];
            if(firstData == 0 && count >= d / 2){
                firstData = i;
            }
            if(secondData == 0 && count >= d / 2 + 1){
                secondData = i;
                break;
            }
        }
        median = (firstData + secondData) / 2.0;
    }
    return median;
}
// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int moneyInDate[201] = {0}, count = 0;
    for(int i = 0; i < d; i++)
        moneyInDate[expenditure[i]]++;
    for(int i = d; i < expenditure.size(); i++){
        double median = getMedian(moneyInDate, d);
        if(median * 2 <= expenditure[i])
            count++;
        moneyInDate[expenditure[i - d]]--;
        moneyInDate[expenditure[i]]++;
    }
    return count;
}