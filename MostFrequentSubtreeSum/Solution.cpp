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
    int sumHelper(TreeNode* node, vector<int>& sums) {
        if (node == NULL) return 0;
        int l = sumHelper(node->left, sums);
        int r = sumHelper(node->right, sums);
        int sum = node->val + l + r;
        sums.push_back(sum);
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> sums;
        sumHelper(root, sums);
        sort(sums.begin(), sums.end());
        int cnt = 0;
        int maxCnt = 0;
        for (int i = 0; i < sums.size(); i++) {
            if (i == 0) {
                cnt = 1;
            } else {
                if (sums[i] == sums[i - 1]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }
            if (maxCnt < cnt) {
                maxCnt = cnt;
            }
        }
        vector<int> res;
        for (int i = 0; i < sums.size(); i++) {
            if (i == 0) {
                cnt = 1;
            } else {
                if (sums[i] == sums[i - 1]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }
            if (cnt == maxCnt) {
                res.push_back(sums[i]);
            }
        }
        return res;
    }
};