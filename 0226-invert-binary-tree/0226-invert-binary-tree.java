
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
    public TreeNode invertTree(TreeNode root) {
        inorderTraverse(root);
        return root;
    }
    
    public void inorderTraverse(TreeNode node) {
        if(node != null) {
            swap(node);
            inorderTraverse(node.left);
            inorderTraverse(node.right);
        }
    }
    
    public void swap(TreeNode node) {
        if(node. left != null || node.right != null) {
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
    }
}