import java.util.*;
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
// 맨 왼쪽이 삭제 될 때
// 맨 오른쪽 삭제
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node = head;
        List<ListNode> nodes = new ArrayList<>();
        while(node != null) {
            nodes.add(node);
            node = node.next;
        }
        if(nodes.size() == 1) {
            return null;
        }
        if(nodes.size() - n == 0) {
            head = head.next;
        } else {
            node = nodes.get(nodes.size() - n - 1);
            node.next = node.next.next;
        }
        return head;
    }
}