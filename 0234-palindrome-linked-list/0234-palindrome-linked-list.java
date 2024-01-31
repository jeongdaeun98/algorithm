/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        String answer = "";
        while(head != null) {
            answer += Integer.toString(head.val);
            head = head.next;
        }
        return isEqual(answer);
    }
    public boolean isEqual(String str) {
        StringBuilder sb = new StringBuilder(str);
        if(sb.reverse().toString().equals(str)) {
            return true;
        }
        return false;
    }
}