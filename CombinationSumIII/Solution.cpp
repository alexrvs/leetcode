class Solution {
private:
    void helper(int k, vector<int>& path, int idx, int sum, vector<vector<int>>& res) {
        if (k < 0 || sum < 0) return;
        if (k == 0 && sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i <= 9; i++) {
            path.push_back(i);
            helper(k - 1, path, i + 1, sum - i, res);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helper(k, path, 1, n, res);
        return res;
    }
};
