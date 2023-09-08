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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        AtomicBoolean target = new AtomicBoolean(false);
        traversal(root, targetSum, target);
        return target.get();
    }
    public void traversal(TreeNode node, int sum, AtomicBoolean target) {
        if(node!= null) {
            if(node.left == null && node.right == null) {
                if(sum - node.val == 0) {
                    target.set(true);
                }
            }
            traversal(node.left, sum - node.val, target);
            traversal(node.right, sum - node.val, target);
        }
    }
}