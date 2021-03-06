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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (size == 0) return NULL;
        stack<TreeNode*> st;
        TreeNode root(INT_MIN);
        TreeNode* cur = NULL;
        st.push(&root);
        int inIdx = 0;
        int preIdx = 0;
        while (inIdx < size) {
            if (st.top()->val == inorder[inIdx]) {
                cur = st.top();
                st.pop();
                inIdx++;
            } else if (cur != NULL) {
                cur->right = new TreeNode(preorder[preIdx++]);
                st.push(cur->right);
                cur = NULL;
            } else {
                st.top()->left = new TreeNode(preorder[preIdx++]);;
                st.push(st.top()->left);
            }
        }
        return root.left;
    }
}; 