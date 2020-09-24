#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;
//출처 : https://wiserloner.tistory.com/323 split 함수
vector<string> split(string str, char delimiter) 
{
	vector<string> internal;
	stringstream ss(str);
	string temp;


	while (getline(ss, temp, delimiter)) 
	{
		internal.push_back(temp);
	}

	return internal;
}

int solution(vector<string> id_list, int k) {
    int answer = 0;
    unordered_map<string,int> couponMap;
    for(int i = 0; i < id_list.size(); i++){
        vector<string> guestVector = split(id_list[i], ' ');
        unordered_map<string,bool> todayGuestMap; 
        for(string guest : guestVector){
            unordered_map<string,bool> :: iterator todayIter = todayGuestMap.find(guest);
            unordered_map<string,int> :: iterator guestIter = couponMap.find(guest);
            if(todayIter != todayGuestMap.end()) continue;
            todayGuestMap.insert(make_pair(guest, true));
            if(guestIter != couponMap.end()){
                if(guestIter-> second < k){
                    int presentCouponNum = guestIter-> second;
                    couponMap.erase(guest);
                    couponMap.insert(make_pair(guest, presentCouponNum + 1));
                    answer++;
                    }
            }
            else {
                answer++;
                couponMap.insert(make_pair(guest, 1));
            }
        }
    }
    return answer;
}