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
private:
    int search(int val, vector<int>& inorder, int is, int ie) {
        int l = is;
        int r = ie + 1;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (inorder[m] < val) {
                l = m + 1;
            } else if (inorder[m] > val) {
                r = m;
            } else {
                return m;
            }
        }
        return l;
    }
    
    TreeNode* helper(vector<int>& preorder, int ps, vector<int>& inorder, int is, int ie) {
        if (is > ie) return NULL;
        int val = preorder[ps];
        TreeNode* node = new TreeNode(val);
        int i = search(val, inorder, is, ie);
        node->left = helper(preorder, ps + 1, inorder, is, i - 1);
        node->right = helper(preorder, ps + 1 + i - is, inorder, i + 1, ie);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, inorder, 0, inorder.size() - 1);
    }
};