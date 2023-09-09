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
    public int getMinimumDifference(TreeNode root) {
        List<Integer> nodes = new ArrayList<>();
        int answer = Integer.MAX_VALUE;
        traversal(nodes, root);
        Collections.sort(nodes);
        for(int i = 0; i < nodes.size() - 1; i++) {
            answer = Math.min(answer, nodes.get(i + 1) - nodes.get(i));
        }
        return answer;
    }
    public void traversal(List<Integer> nodes, TreeNode node) {
        if(node == null){
            return;
        }
        nodes.add(node.val);
        traversal(nodes, node.left);
        traversal(nodes, node.right);
    }
}