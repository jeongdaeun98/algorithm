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
    public ListNode swapPairs(ListNode head) {
        List<ListNode> nodes = new ArrayList<>();
        if(head == null || head.next == null) {
            return head;
        }
        ListNode node = head.next;
        while(head.next != null) {
            node = head.next;
            head.next = null;
            nodes.add(head);
            head = node;
        }
        nodes.add(node);
        for(int i = 0; i < nodes.size(); i= i+2) {
            if(i + 1 >= nodes.size()){
                break;
            }
            ListNode nextNode = nodes.get(i);
            nodes.set(i, nodes.get(i + 1));
            nodes.set(i + 1, nextNode);
        }
        for(int i = 0; i < nodes.size(); i++) {
            if(i + 1 >= nodes.size()) {
                break;
            }
            nodes.get(i).next = nodes.get(i + 1);
        }
        return nodes.get(0);
    }
}