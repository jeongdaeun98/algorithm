class Solution {
    public boolean exist(char[][] board, String word) {
        boolean visited[][] = new boolean[board.length][board[0].length];
        if(word.length() == 0) {
            return true;
        }
        for(int i = 0; i < board.length ; i++) {
            for(int j = 0; j < board[i].length; j++) {
                if(combination(board, word,0, i,j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    public boolean combination(char[][]board, String word, int index, int i, int j, boolean visited[][]) {
        if(word.length() == index) {
            return true;
        }
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length){
            return false;
        }
        if(visited[i][j]){
            return false;
        }
        if(word.charAt(index) == board[i][j]) {
            visited[i][j] = true;
            boolean result = combination(board, word, index + 1, i, j + 1, visited) ||
                combination(board, word, index + 1, i + 1, j, visited) ||
                combination(board, word, index+ 1, i, j -1, visited) ||
                combination(board, word, index + 1, i - 1, j, visited);
            if(result){
                return true;
            } else {
                visited[i][j] = false;
            }
        }
        return false;
    }
}