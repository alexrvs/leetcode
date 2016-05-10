/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {

    private List<TreeNode> order;
    private int cur;

    private void helper(TreeNode node) {
        if (node == null) return;
        helper(node.left);
        order.add(node);
        helper(node.right);
        return;
    }

    public BSTIterator(TreeNode root) {
        order = new ArrayList<TreeNode>();
        cur = 0;
        helper(root);
        return;
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return (cur != order.size());
    }

    /** @return the next smallest number */
    public int next() {
        int val = order.get(cur).val;
        cur++;
        return val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
