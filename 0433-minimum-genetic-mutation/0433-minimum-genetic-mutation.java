import java.util.*;
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Queue<String> q = new LinkedList<>();
        Map<String,Integer> visited = new HashMap<>();
        q.add(startGene);
        visited.put(startGene, 0);
        
        while(!q.isEmpty()) {
            String gene = q.poll();
            if(gene.equals(endGene)){
                return visited.get(gene);
            }
            for(int i = 0; i < bank.length; i++) {
                if(!visited.containsKey(bank[i])) {
                    int check = 0;
                    String newGene = bank[i];
                    for(int j = 0; j < gene.length(); j++) {
                        if(gene.charAt(j) != newGene.charAt(j)) {
                            check++;
                        }
                    }
                    if(check == 1) {
                        q.add(bank[i]);
                        visited.put(bank[i] , visited.get(gene) + 1);
                    }
                }
            }
        }
        return -1;
    }
}