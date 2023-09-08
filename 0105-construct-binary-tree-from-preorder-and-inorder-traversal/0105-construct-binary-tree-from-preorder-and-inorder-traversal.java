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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return generateTree(preorder, inorder,0, 0, inorder.length - 1);
    }
    public TreeNode generateTree(int[] preorder, int[] inorder,int preorderIndex,int inorderStartIndex, int inorderEndIndex) {
        if(preorderIndex >= preorder.length || inorderStartIndex >inorderEndIndex) {
            return null;
        }
        TreeNode node = new TreeNode(preorder[preorderIndex]);
        int inorderIndex = 0;
        for(int i = inorderStartIndex; i <= inorderEndIndex; i++) {
            if(node.val == inorder[i]) {
                inorderIndex = i;
                break;
            }
        }
        node.left = generateTree(preorder, inorder, preorderIndex + 1, inorderStartIndex, inorderIndex -1);
        node.right = generateTree(preorder, inorder, preorderIndex + inorderIndex - inorderStartIndex +1, inorderIndex + 1, inorderEndIndex);
        return node;
    }
}