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
    int sumHelper(TreeNode node, List<Integer> sums) {
        if (node == null) return 0;
        int l = sumHelper(node.left, sums);
        int r = sumHelper(node.right, sums);
        int sum = node.val + l + r;
        sums.add(sum);
        return sum;
    }

    public int[] findFrequentTreeSum(TreeNode root) {
        List<Integer> sums = new ArrayList<Integer>();
        sumHelper(root, sums);
        Collections.sort(sums);
        int cnt = 0;
        int maxCnt = 0;
        for (int i = 0; i < sums.size(); i++) {
            if (i == 0) {
                cnt = 1;
            } else {
                if (sums.get(i).equals(sums.get(i - 1))) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }
            if (maxCnt < cnt) {
                maxCnt = cnt;
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < sums.size(); i++) {
            if (i == 0) {
                cnt = 1;
            } else {
                if (sums.get(i).equals(sums.get(i - 1))) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }
            if (cnt == maxCnt) {
                res.add(sums.get(i));
            }
        }
        int[] resArr = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            resArr[i] = res.get(i);
        }
        return resArr;
    }
}