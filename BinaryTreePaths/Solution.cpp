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
    vector<string> paths;

    string getstring(const int n) {
        stringstream newstr;
        newstr << n;
        return newstr.str();
    }

    void helper(string path, TreeNode* node) {
        if (node == NULL) return;
        path += getstring(node->val);
        if (node->left == NULL && node->right == NULL) {
            paths.push_back(path);
            return;
        }
        if (node->left != NULL) helper(path + "->", node->left);
        if (node->right != NULL) helper(path + "->", node->right);
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        helper(path, root);
        return paths;
    }
};
