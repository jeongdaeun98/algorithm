class Solution {
    public int reverse(int x) {
        Boolean minus = false;
        Long positiveValue = Long.parseLong(String.valueOf(x));
        if(x < 0) {
            minus = true;
            positiveValue = positiveValue * -1;
        }
        String numberStr = String.valueOf(positiveValue);
        StringBuffer sb = new StringBuffer(numberStr);
        String reversedNumStr = sb.reverse().toString();
        Long reversedNum = Long.parseLong(reversedNumStr);
        if(minus) reversedNum = reversedNum * -1;
        if(Integer.MAX_VALUE < reversedNum || Integer.MIN_VALUE > reversedNum) {
            return 0;
        }
        return Integer.parseInt(reversedNum.toString());
    }
}