class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] sOne = new int['z' -'a' + 1];
        int[] sTwo = new int['z' - 'a' + 1];
        Arrays.fill(sOne, 0);
        Arrays.fill(sTwo, 0);
        for(int i = 0; i < s1.length(); i++) {
            sOne[s1.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s2.length(); i++) {
            sTwo[s2.charAt(i) - 'a']++;
            if(i >= s1.length()) {
                sTwo[s2.charAt(i - s1.length()) -'a']--;
            }
            if(i >= s1.length() - 1 && checkSame(sOne, sTwo)) {
                return true;
            }
        }
        return false;
    }
    public boolean checkSame(int[]s1, int[]s2) {
        for(int i = 0; i < s1.length; i++) {
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
}