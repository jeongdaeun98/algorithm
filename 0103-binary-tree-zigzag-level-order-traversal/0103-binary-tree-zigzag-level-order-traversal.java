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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> answer = new ArrayList<>();
        Map<Integer, List<Integer>> depthAndNodes = new HashMap<>();
        traversal(root, depthAndNodes, 0);
        for(int depth : depthAndNodes.keySet()) {
            List<Integer> nodes = depthAndNodes.get(depth);
            if(depth % 2 == 1) {
                Collections.reverse(nodes);
                answer.add(nodes);
            } else {
                answer.add(nodes);
            }
        }
        return answer;
    }
    public void traversal(TreeNode node, Map<Integer, List<Integer>> depthAndNodes, int depth) {
        if(node == null) {
            return;
        }
        if(depthAndNodes.containsKey(depth)) {
            depthAndNodes.get(depth).add(node.val);
        } else {
            List<Integer> nodes = new ArrayList<>();
            nodes.add(node.val);
            depthAndNodes.put(depth, nodes);
        }
        traversal(node.left, depthAndNodes, depth + 1);
        traversal(node.right, depthAndNodes, depth + 1);
    }
}