// 10%가 원단위로 절사했을 때 금액이 1원 미만이면 다 가짐.
// 줘야할 사람이 없더라도 10%만큼 이익 제거
// 사람, 금액으로 hashmap 초기화
// 사람, 사람으로 hashMap 초기화
// enroll 별로 result 리턴
// dfs
// young 1200 - 1200 * 0.1 = 120
import java.util.*;
class Solution {
    public void dfs(Map<String, String> enrollAndReferral, Map<String, Integer> personAndMoney, int price, String name) {
        if(name.equals("-")) {
            return;
        }
        if((int)(price * 0.1) <= 0) {
            personAndMoney.put(name, personAndMoney.getOrDefault(name, 0) + price - (int)(price*0.1));

        } else {
            personAndMoney.put(name, personAndMoney.getOrDefault(name, 0) + price - (int)(price*0.1));
            dfs(enrollAndReferral, personAndMoney, (int)(price * 0.1), enrollAndReferral.get(name));
        }
    }
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        Map<String, String> enrollAndReferral = new HashMap<>();
        Map<String, Integer> personAndMoney = new HashMap<>();
        for(int i = 0; i < enroll.length; i++) {
            enrollAndReferral.put(enroll[i], referral[i]);
            personAndMoney.put(enroll[i], 0);
            personAndMoney.put(referral[i], 0);
        }
        for(int i = 0; i < seller.length; i++) {
            dfs(enrollAndReferral, personAndMoney, amount[i] * 100, seller[i]);
        }
        for(int i = 0; i < enroll.length; i++) {
            answer[i] = personAndMoney.get(enroll[i]);
        }
        return answer;
    }
}
