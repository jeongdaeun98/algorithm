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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        traversal(answer, root);
        return answer;
    }
    public void traversal(List<Integer> answer, TreeNode node) {
        if(node == null) {
            return;
        }
        answer.add(node.val);
        traversal(answer, node.left);
        traversal(answer, node.right);
    }
}