public class Solution {
    int orderIdx = 0;

    private class TreeNode {
        int val;
        boolean isNullNode;
        TreeNode left;
        TreeNode right;

        TreeNode() {
            this.isNullNode = false;
            this.left = null;
            this.right = null;
        }

        public void setValue(int val) {
            this.val = val;
        }

        public int getValue() {
            return this.val;
        }

        public void setNull() {
            this.isNullNode = true;
        }

        public boolean isNull() {
            return this.isNullNode;
        }
    }

    private boolean build(String preorder, TreeNode node) {
        int size = preorder.length();
        if (orderIdx >= size) {
            return false;
        }
        char c = preorder.charAt(orderIdx);
        if (c == '#') {
            node.setNull();
            orderIdx += 2;
        } else {
            boolean suc = true;
            int next = orderIdx;
            while (next < size && preorder.charAt(next) != ',') next++;
            if (next == size) {
                node.setValue(Integer.parseInt(preorder.substring(orderIdx)));
            } else {
                node.setValue(Integer.parseInt(preorder.substring(orderIdx, next)));
            }
            orderIdx = next + 1;
            node.left = new TreeNode();
            suc = build(preorder, node.left);
            if (suc == false) return false;
            node.right = new TreeNode();
            suc = build(preorder, node.right);
            if (suc == false) return false;
        }
        return true;
    }

    public boolean isValidSerialization(String preorder) {
        int size = preorder.length();
        if (size == 0) return false;
        orderIdx = 0;
        TreeNode root = new TreeNode();
        boolean suc = build(preorder, root);
        if (suc == false || this.orderIdx != size + 1) return false;
        return true;
    }
}
