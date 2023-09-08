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
    public boolean isSymmetric(TreeNode root) {
        List<Integer> leftArray = new ArrayList<>();
        inorderTraverseAndSwap(root.left, leftArray);
        List<Integer> rightArray = new ArrayList<>();
        inorderTraverse(root.right, rightArray);
        if(leftArray.size()!= rightArray.size()) {
            return false;
        }
        for(int i = 0; i < leftArray.size(); i++) {
            if(leftArray.get(i) != rightArray.get(i)) {
                return false;
            }
        }
        return true;
    }
    public void inorderTraverseAndSwap(TreeNode node, List<Integer> array) {
        if(node == null) {
            array.add(null);
        }
        if(node != null) {
            swap(node);
            array.add(node.val);
            inorderTraverseAndSwap(node.left, array);
            inorderTraverseAndSwap(node.right, array);
        }
    }
    
    public void inorderTraverse(TreeNode node, List<Integer>array) {
        if(node == null) {
            array.add(null);
        }
        if(node != null) {
            array.add(node.val);
            inorderTraverse(node.left, array);
            inorderTraverse(node.right, array);
        }
    }
    
    public void swap(TreeNode node) {
        if(node.left != null || node.right != null) {
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
    }
}