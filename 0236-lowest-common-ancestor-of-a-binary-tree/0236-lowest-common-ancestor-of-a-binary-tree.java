import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode answer = null;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Set<Integer> nodes = new HashSet<>();
        traversal(root, p, q);
        return answer;
    }
    public int traversal(TreeNode node, TreeNode p, TreeNode q) {
        int count = 0;
        if(node != null) {
            if(node.val == p.val || node.val == q.val) {
                count++;
            }
            count += traversal(node.left, p, q);
            count += traversal(node.right, p, q);
            if(count == 2 && answer == null) {
                answer = node;
            }
            return count;
        }
        return 0;
    }
}