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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int[] postorderReverse = new int[postorder.length];
        for(int i = 0; i < postorder.length; i++) {
            postorderReverse[i] = postorder[postorder.length - 1 - i];
        }
        return generateTree(inorder, postorderReverse, 0, 0, inorder.length - 1);
    }
    public TreeNode generateTree(int[] inorder, int[] postorder, int postorderIndex, int inorderStartIndex, int inorderEndIndex) {
        if(postorderIndex >= postorder.length || inorderStartIndex > inorderEndIndex){
            return null;
        }
        TreeNode node = new TreeNode(postorder[postorderIndex]);
        int inorderIndex = 0;
        for(int i = inorderStartIndex; i <= inorderEndIndex; i++) {
            if(postorder[postorderIndex] == inorder[i]){
                inorderIndex = i;
                break;
            }
        }
        node.right = generateTree(inorder, postorder, postorderIndex + 1, inorderIndex + 1, inorderEndIndex);
        node.left = generateTree(inorder, postorder, postorderIndex + inorderEndIndex - inorderIndex + 1, inorderStartIndex, inorderIndex -1);
        return node;
    }
}