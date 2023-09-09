import java.util.*;
import java.math.*;
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
    public List<Double> averageOfLevels(TreeNode root) {
        Map<Integer, BigDecimal> nodeTotal = new HashMap<>();
        Map<Integer, BigDecimal> nodeCount = new HashMap<>();
        List<Double> averages = new ArrayList<>();
        traversal(nodeTotal, root, 1, nodeCount);
        for(int depth : nodeTotal.keySet()) {
            averages.add(nodeTotal.get(depth).divide(nodeCount.get(depth), 5, RoundingMode.FLOOR).doubleValue());
        }
        return averages;
    }
    public void traversal(Map<Integer, BigDecimal> nodeTotal, TreeNode node, int depth, Map<Integer, BigDecimal> nodeCount) {
        if(node == null) {
            return;
        }
        nodeCount.put(depth, nodeCount.getOrDefault(depth, new BigDecimal("0")).add(new BigDecimal("1")));
        nodeTotal.put(depth, nodeTotal.getOrDefault(depth, new BigDecimal("0")).add(new BigDecimal(Integer.toString(node.val))));        
        traversal(nodeTotal, node.left, depth + 1, nodeCount);
        traversal(nodeTotal, node.right, depth + 1, nodeCount);
    }
}