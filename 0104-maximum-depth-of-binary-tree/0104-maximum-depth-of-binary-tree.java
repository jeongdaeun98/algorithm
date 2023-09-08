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
    public int maxDepth(TreeNode root) {
        AtomicInteger maxDepth = new AtomicInteger(0);
        int depth = 1;
        inOrderTraverse(root, depth, maxDepth);
        return maxDepth.get();
    }
    
    public void inOrderTraverse(TreeNode node, int depth, AtomicInteger maxDepth) {
        if(node != null) {
            maxDepth.set(Math.max(maxDepth.get(), depth));
            inOrderTraverse(node.left, depth + 1, maxDepth);
            inOrderTraverse(node.right, depth + 1, maxDepth);
        }
    }
}