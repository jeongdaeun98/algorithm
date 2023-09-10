class Solution {
    public int ladderLength(String startGene, String endGene, List<String> bank) {
        Queue<String> q = new LinkedList<>();
        Map<String,Integer> visited = new HashMap<>();
        q.add(startGene);
        visited.put(startGene, 1);
        
        while(!q.isEmpty()) {
            String gene = q.poll();
            if(gene.equals(endGene)){
                return visited.get(gene);
            }
            for(int i = 0; i < bank.size(); i++) {
                if(!visited.containsKey(bank.get(i))) {
                    int check = 0;
                    String newGene = bank.get(i);
                    for(int j = 0; j < gene.length(); j++) {
                        if(gene.charAt(j) != newGene.charAt(j)) {
                            check++;
                        }
                    }
                    if(check == 1) {
                        q.add(bank.get(i));
                        visited.put(bank.get(i) , visited.get(gene) + 1);
                    }
                }
            }
        }
        return 0;
    }
}
