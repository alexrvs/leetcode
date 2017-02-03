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
    void cntHelper(TreeNode* node, int* cnt, int* maxCnt, int* prev) {
        if (node == NULL) return;
        cntHelper(node->left, cnt, maxCnt, prev);
        if (*cnt == 0) {
            *prev = node->val;
            *cnt = 1;
        } else {
            if (*prev == node->val) {
                *cnt = *cnt + 1;
            } else {
                *prev = node->val;
                *cnt = 1;
            }
        }
        if (*maxCnt < *cnt) {
            *maxCnt = *cnt;
        }
        cntHelper(node->right, cnt, maxCnt, prev);
        return;
    }
    
    void pickHelper(vector<int>& res, TreeNode* node, int* cnt, int maxCnt, int* prev) {
        if (node == NULL) return;
        pickHelper(res, node->left, cnt, maxCnt, prev);
        if (*cnt == 0) {
            *prev = node->val;
            *cnt = 1;
        } else {
            if (*prev == node->val) {
                *cnt = *cnt + 1;
            } else {
                *prev = node->val;
                *cnt = 1;
            }
        }
        if (maxCnt == *cnt) {
            res.push_back(node->val);
        }
        pickHelper(res, node->right, cnt, maxCnt, prev);
        return;
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        int cnt = 0;
        int maxCnt = 0;
        int prev = 0;
        vector<int> res;
        cntHelper(root, &cnt, &maxCnt, &prev);
        cnt = 0;
        pickHelper(res, root, &cnt, maxCnt, &prev);
        return res;
    }
};