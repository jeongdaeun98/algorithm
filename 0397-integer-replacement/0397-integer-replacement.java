class Solution {
    public int integerReplacement(int n) {
        return recursion((long)n);
    }
    public int recursion(long i) {
        if(i <= 1) {
            return 0;
        }
        if(i % 2 == 0) {
            return recursion(i / 2) + 1;
        } else {
            return Math.min(recursion(i + 1), recursion(i - 1)) + 1;
        }
    }
}