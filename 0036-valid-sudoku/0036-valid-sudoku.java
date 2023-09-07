public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i++) {
            Set<Character> rows = new HashSet<>();
            Set<Character> columns = new HashSet<>();
            Set<Character> boxes = new HashSet<>();
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' && !rows.add(board[i][j])) {
                    return false;
                }
                if(board[j][i] != '.' && !columns.add(board[j][i])) {
                    return false;
                }
                int a = 3 * (i % 3);
                int b = 3 * (i / 3);
                if(board[a + j % 3][b + j / 3] != '.' && !boxes.add(board[a + j % 3][b + j / 3])){
                    return false;
                }
            }
        }
        return true;
    }
}