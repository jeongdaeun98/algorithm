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
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode node = head;
        List<ListNode> nodes = new ArrayList<>();
        while(node != null) {
            nodes.add(node);
            node = node.next;
        }
        if(nodes.size() == 0) {
            return head;
        }
        k = k % nodes.size();
        ListNode newHead = head;
        if((nodes.size() - k) >= 0 && nodes.size() - k < nodes.size()){
            newHead = nodes.get(nodes.size() - k);
            nodes.get(nodes.size() - 1).next = nodes.get(0);
            nodes.get(nodes.size() - k - 1).next = null;
        }
        return newHead;
    }
}