/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        if (size == 0) return NULL;
        TreeNode root(INT_MIN);
        stack<TreeNode*> st;
        st.push(&root);
        TreeNode* cur = NULL;
        int postIdx = size - 1;
        int inIdx = size - 1;
        while (postIdx >= 0) {
            if (st.top()->val == inorder[inIdx]) {
                cur = st.top();
                st.pop();
                inIdx--;
            } else if (cur != NULL) {
                cur->left = new TreeNode(postorder[postIdx--]);
                st.push(cur->left);
                cur = NULL;
            } else {
                st.top()->right = new TreeNode(postorder[postIdx--]);
                st.push(st.top()->right);
            }
        }
        return root.right;
    }
};