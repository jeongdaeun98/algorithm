//1. Stack에 집어넣고
//2. 절반까지만 순회하면서 stack에 집어넣은 거 넣기
//3. 순회 끝나면 마지막 node에 null값으로 집어넣음.
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
    public void reorderList(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode temp = head;
        while(temp != null) {
            stack.push(temp);
            temp = temp.next;
        }
        int n = stack.size();
        for(int i = 0; i < n / 2; i++) {
            temp = stack.pop();
            temp.next = head.next;
            head.next = temp;
            head = temp.next;
        }
        head.next = null;
    }
}