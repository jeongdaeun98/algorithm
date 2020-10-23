#include <vector>

using namespace std;

int solution(vector<vector<int>> rates, vector<vector<int>> customers) {
    int answer = 0;
    int minMoney = 987654321;
    for(int i = 0; i < customers.size(); i++){
        for(int j = 0; j < rates.size(); j++){
            int money = rates[j][0];
            if(rates[j][1] != -1 && customers[i][0] - rates[j][1] > 0){
                money += (customers[i][0] - rates[j][1])*rates[j][2]*60;
            }
            if(rates[j][3] != -1 && customers[i][1] - rates[j][3] > 0){
                money += (customers[i][1] - rates[j][3])*rates[j][4];
            }
            if(rates[j][5] != -1 && customers[i][2] - rates[j][5] > 0) {
                money += (customers[i][2] - rates[j][5])*rates[j][6];
            }
            if(minMoney > money) minMoney = money;
        }
        answer += minMoney;
    }
    return answer;
}