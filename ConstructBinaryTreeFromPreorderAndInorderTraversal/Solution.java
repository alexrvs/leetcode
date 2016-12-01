/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    private int search(int val, int[] inorder, int is, int ie) {
        int l = is;
        int r = ie + 1;
        int m = 0;
        for (m = l; m < r; m++) {
            if (inorder[m] == val) break;
        }
        return m;
    }
    
    private TreeNode helper(int[] preorder, int ps, int[] inorder, int is, int ie) {
        if (is > ie || ps >= preorder.length) return null;
        int val = preorder[ps];
        TreeNode node = new TreeNode(val);
        int i = search(val, inorder, is, ie);
        node.left = helper(preorder, ps + 1, inorder, is, i - 1);
        node.right = helper(preorder, ps + 1 + i - is, inorder, i + 1, ie);
        return node;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, inorder, 0, inorder.length - 1);
    }
}