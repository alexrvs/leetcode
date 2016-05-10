/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> m_stack;

    void helper(TreeNode *node) {
        while (node != NULL) {
            m_stack.push(node);
            node = node->left;
        }
        return;
    }

public:
    BSTIterator(TreeNode *root) {
        helper(root);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (m_stack.size() != 0);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = m_stack.top();
        m_stack.pop();
        helper(node->right);
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
