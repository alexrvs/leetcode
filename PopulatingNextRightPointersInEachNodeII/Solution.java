/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeLinkNode firstNextChild(TreeLinkNode node) {
        while (node != null) {
            if (node.left != null) return node.left;
            if (node.right != null) return node.right;
            node = node.next;
        }
        return null;
    }

    public void connect(TreeLinkNode root) {
        if (root == null) return;
        TreeLinkNode node = root;
        while (node != null) {
            if (node.left != null) {
                if (node.right != null) {
                    node.left.next = node.right;
                } else {
                    node.left.next = firstNextChild(node.next);
                }
            }
            if (node.right != null) {
                node.right.next = firstNextChild(node.next);
            }
            node = node.next;
        }
        connect(root.left);
        connect(root.right);
    }
}
