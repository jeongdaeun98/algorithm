class Solution {
    public int lengthOfLastWord(String s) {
        boolean isEmpty = true;
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            Character c = s.charAt(i);
            if(c != ' ') {
                isEmpty = false;
                count++;
            }
            if(!isEmpty && c == ' ') {
                break;
            }
        }
        return count;
    }
}