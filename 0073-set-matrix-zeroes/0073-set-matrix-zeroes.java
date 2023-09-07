class Solution {
    // 1. 0의 위치 파악하여 index list에 추가
    // 2.  index list 순회
    // 3. row 전체를 0
    // 4. column 전체 0
    public void setZeroes(int[][] matrix) {
        List<List<Integer>> indexes = new ArrayList<>();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++) {
                if(matrix[i][j] == 0){
                    List<Integer> index = new ArrayList<>();
                    index.add(i);
                    index.add(j);
                    indexes.add(index);
                }
            }
        }
        int index = 0;
        while(index < indexes.size()) {
            int i = indexes.get(index).get(0);
            int j = 0;
            while(j < matrix[i].length) {
                matrix[i][j] = 0;
                j++;
            }
            i = 0;
            j = indexes.get(index).get(1);
            while(i < matrix.length) {
                matrix[i][j] = 0;
                i++;
            }
            index++;
        }
    }
}