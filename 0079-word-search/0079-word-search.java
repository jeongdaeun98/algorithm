class Solution {
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[i].length; j++) {
                if(combination(board, visited, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    
    public boolean combination(char[][] board, boolean[][] visited, String word, int index, int i, int j) {
        if(index == word.length()) {
            return true;
        }
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length) {
            return false;
        }
        if(visited[i][j]) {
            return false;
        }
        if(word.charAt(index) == board[i][j]){
            visited[i][j] = true;
            boolean result = combination(board, visited, word, index + 1, i + 1, j)
            || combination(board, visited, word, index + 1, i, j + 1)
            || combination(board, visited, word, index + 1, i - 1, j)
            || combination(board, visited, word, index + 1, i, j - 1);
            if(!result) {
                visited[i][j] = false;
            }
            return result;
        }
        return false;
    }
}