/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        AtomicBoolean answer = new AtomicBoolean(true);
        traversal(root, null, null, answer);
        return answer.get();
    }
    public void traversal(TreeNode node, Integer max, Integer min, AtomicBoolean answer) {
        if(node == null) {
            return;
        }
        if(max != null && max <= node.val) {
            answer.set(false);
            return;
        }
        if(min != null && min >= node.val) {
            answer.set(false);
            return;
        }
        traversal(node.left, node.val, min, answer);
        traversal(node.right, max, node.val, answer);
    }
}