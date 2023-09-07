class Solution {
    //[i][j] 
    //1. j 증가 limit까지
    //2. i 증가 limit까지
    //3. j 감소 0까지
    //4. i 감소 0까지(그러나 0 지났으니까 그 직전에서 다시 1 반복)
    public List<Integer> spiralOrder(int[][] matrix) {
        List<List<Boolean>> visit = new ArrayList<>();
        for(int i = 0; i < matrix.length; i++) {
            List<Boolean> visitArray = new ArrayList<>();
            for(int j = 0; j < matrix[i].length; j++) {
                visitArray.add(false);
            }
            visit.add(visitArray);
        }
        int i = 0;
        int j = 0;
        boolean push = true;
        List<Integer> array = new ArrayList<>();
        while(push) {
            push = false;
            while(j < matrix[i].length && !visit.get(i).get(j)) {
                array.add(matrix[i][j]);
                visit.get(i).set(j, true);
                push = true;
                j++;
            }
            j--;
            i++;
            while(i < matrix.length && !visit.get(i).get(j)) {
                array.add(matrix[i][j]);
                visit.get(i).set(j, true);
                push = true;
                i++;
            }
            i--;
            j--;
            while(j >= 0 && !visit.get(i).get(j)) {
                array.add(matrix[i][j]);
                visit.get(i).set(j, true);
                push = true;
                j--;
            }
            j++;
            i--;
            while(i >= 0 && !visit.get(i).get(j)) {
                array.add(matrix[i][j]);
                visit.get(i).set(j, true);
                push = true;
                i--;
            }
            i++;
            j++;
        }
        return array;
    }
}