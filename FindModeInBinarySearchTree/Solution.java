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
    
    private int cnt;
    private int maxCnt;
    private int prev;
    
    void cntHelper(TreeNode node) {
        if (node == null) return;
        cntHelper(node.left);
        if (cnt == 0) {
            prev = node.val;
            cnt = 1;
        } else {
            if (prev == node.val) {
                cnt = cnt + 1;
            } else {
                prev = node.val;
                cnt = 1;
            }
        }
        if (maxCnt < cnt) {
            maxCnt = cnt;
        }
        cntHelper(node.right);
        return;
    }
    
    private void pickHelper(List<Integer> res, TreeNode node) {
        if (node == null) return;
        pickHelper(res, node.left);
        if (cnt == 0) {
            prev = node.val;
            cnt = 1;
        } else {
            if (prev == node.val) {
                cnt = cnt + 1;
            } else {
                prev = node.val;
                cnt = 1;
            }
        }
        if (maxCnt == cnt) {
            res.add(node.val);
        }
        pickHelper(res, node.right);
        return;
    }
    
    public int[] findMode(TreeNode root) {
        this.cnt = 0;
        this.maxCnt = 0;
        cntHelper(root);
        List<Integer> res = new ArrayList<Integer>();
        this.cnt = 0;
        pickHelper(res, root);
        int[] resArr = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            resArr[i] = res.get(i);
        }
        return resArr;
    }
}