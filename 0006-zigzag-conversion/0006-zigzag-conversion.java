import java.util.*;
class Solution {
    public String convert(String s, int numRows) {
        String[] tempString = new String[numRows];
        if(numRows == 1) {
            return s;
        }
        for(int i = 0; i < numRows; i++) {
            tempString[i] = "";
        }
        for(int i = 0; i < s.length(); i++) {
            int index = i % (2*(numRows - 1));
            if(index >= numRows) {
                index = 2*(numRows - 1) - index;
            }
            tempString[index] += Character.toString(s.charAt(i));
        }
        return Arrays.stream(tempString).collect(Collectors.joining());
    }
}