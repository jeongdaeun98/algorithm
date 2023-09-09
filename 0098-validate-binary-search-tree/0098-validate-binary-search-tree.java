import java.util.*;
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
        AtomicBoolean valid = new AtomicBoolean(true);
        traverse(null, null, root, valid);
        return valid.get();
    }
    public void traverse(Integer min, Integer max, TreeNode node, AtomicBoolean valid) {
        if(node == null || !valid.get()) {
            return;
        }
        if(max != null && max <= node.val) {
            valid.set(false);
            return;
        }
        if(min != null && min >= node.val) {
            valid.set(false);
            return;
        }
        traverse(min, node.val ,node.left, valid);
        traverse(node.val, max, node.right, valid);
    }
}