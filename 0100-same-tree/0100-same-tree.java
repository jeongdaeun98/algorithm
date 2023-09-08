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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        List<Integer> pArray = new ArrayList<>();
        List<Integer> qArray = new ArrayList<>();
        inorderTraverse(p, pArray);
        inorderTraverse(q, qArray);
        for(int i = 0; i < pArray.size(); i++) {
            Integer pNum = pArray.get(i);
            Integer qNum = qArray.get(i);
            if((pNum == null && qNum != null) || (pNum != null && qNum == null)){
                return false;
            }
            if(pNum != null && qNum != null&& !pNum.equals(qNum)){
                return false;
            }
        }
        return true;
    }
    public void inorderTraverse(TreeNode node, List<Integer> array) {
        if(node == null) {
            array.add(null);
        }
        if(node != null) {
            array.add(node.val);
            inorderTraverse(node.left, array);
            inorderTraverse(node.right, array);
        }
    }
}