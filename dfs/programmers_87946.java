import java.util.*;
class Solution {
    class P {
        int use;
        int need;
        boolean visit;
        P(int need, int use, boolean visit) {
            this.use = use;
            this.need = need;
            this.visit = visit;
        }
        boolean pass(int k) {
            return k >= need && k >= use;
        }
    }
    int answer = 0;
    public void dfs(int k, int count, List<P> dungeons) {
        for(int i = 0; i < dungeons.size(); i++) {
            answer = Math.max(answer, count);
            if(dungeons.get(i).pass(k) && !dungeons.get(i).visit) {
                dungeons.get(i).visit = true;
                dfs(k - dungeons.get(i).use, count + 1, dungeons);
                dungeons.get(i).visit = false;
            }
        }
    }
    public int solution(int k, int[][] dungeons) {
        List<P> dungeonList = new ArrayList<>();
        for(int i = 0; i < dungeons.length; i++) {
            dungeonList.add(new P(dungeons[i][0], dungeons[i][1], false));
        }
            dfs(k, 0, dungeonList);
        
        return answer;
    }
}
