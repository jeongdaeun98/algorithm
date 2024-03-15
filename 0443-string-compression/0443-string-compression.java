// 순회
// 이전 문자와 같을 때까지 count 증가, 순회
// 이전 문자와 달라질 경우 이전에 저장된 인덱스다음에 count 자릿수 만큼 더해서 count 설정, 
//
class Solution {
    public int compress(char[] chars) {
        int index = 0;
        int count = 0;
        for(int i = 0; i < chars.length;) {
            char letter = chars[i++];
            count++;
            while(i < chars.length && letter == chars[i]) {
                count++;
                i++;
            }
            chars[index++] = letter;
            if(count > 1){
                for(char c : Integer.toString(count).toCharArray()) {
                    chars[index++] = c;
                }
            }
            count = 0;
        }
        return index;
    }
}