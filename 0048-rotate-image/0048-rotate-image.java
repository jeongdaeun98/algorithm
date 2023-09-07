import java.util.*;
class Solution {
    //1. 로테이트 대상 설정
    //2. 로테이트
    //3. 로테이트 되어서 자리 없어진 애랑 새롭게 넣어져야할 index array 추가
    //로테이트 규칙: i -> j swap, j가 변함.
    // j 가장 외곽 left, 외곽 right left ++ right -- left < right까지 swap 
    public void rotate(int[][] matrix) {
        List<Integer> indexes = new ArrayList<>();
        List<List<Boolean>> visited = new ArrayList<>();
        int[][] copy = new int[matrix.length][matrix[0].length];
        for(int i = 0; i < matrix.length; i++) {
            indexes.add(i);
            copy[i] = matrix[i].clone();
            List<Boolean> rows = new ArrayList<>();
            for(int j = 0; j < matrix[i].length; j++) {
                rows.add(false);
            }
            visited.add(rows);
        }
        int left = 0;
        int right = matrix.length - 1;
        while(left < right) {
            swap(indexes, left, right);
            left++;
            right--;
        }
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix.length; j++) {
                while(!visited.get(i).get(j)) {
                visited.get(i).set(j, true);
                int renewI = j;
                int renewJ = indexes.get(i);
                matrix[renewI][renewJ] = copy[i][j];
                i = renewI;
                j = renewJ;
                }
            }
        }
    }
    
    public void swap(List<Integer> indexes, int i, int j) {
        indexes.set(i, j);
        indexes.set(j, i);
    }
    
}