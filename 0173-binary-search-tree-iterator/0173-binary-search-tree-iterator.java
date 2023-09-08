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
class BSTIterator {
    
    List<Integer> inorderNodes;
    int index = 0;
    
    public BSTIterator(TreeNode root) {
        inorderNodes = new ArrayList<>();
        index = 0;
        inorderTraversal(root, inorderNodes);
    }
    
    public int next() {
        return inorderNodes.get(index++).intValue();
    }
    
    public boolean hasNext() {
        return index < inorderNodes.size();
    }
    
    public void inorderTraversal(TreeNode node, List<Integer> inorderNodes) {
        if(node != null) {
            inorderTraversal(node.left, inorderNodes);
            inorderNodes.add(node.val);
            inorderTraversal(node.right, inorderNodes);
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */