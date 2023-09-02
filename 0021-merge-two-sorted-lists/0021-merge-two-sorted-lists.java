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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null) {
            return null;
        } else if(list1 == null){
            return list2;
        } else if(list2 == null) {
            return list1;
        }
        List<ListNode> fullList = new ArrayList<>();
        setNullReferenceNode(fullList, list1);
        setNullReferenceNode(fullList, list2);
        Collections.sort(fullList, new NodeComparator());
        for(int i = 0; i < fullList.size(); i++) {
            if(i + 1 < fullList.size()) {
                fullList.get(i).next = fullList.get(i + 1);
            }
        }
        return fullList.get(0);
    }
    
    public void setNullReferenceNode(List<ListNode> fullList, ListNode list) {
        ListNode node = list;
        while(node.next != null) {
            ListNode nextNode = node.next;
            node.next = null;
            fullList.add(node);
            node = nextNode;
        }
        fullList.add(node);
    }
}
class NodeComparator implements Comparator<ListNode> {
    @Override
    public int compare(ListNode node1, ListNode node2) {
        if(node1.val > node2.val) {
            return 1;
        }
        else if (node1.val < node2.val) {
            return -1;
        }
        return 0;
    }
}