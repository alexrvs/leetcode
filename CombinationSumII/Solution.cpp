class Solution {
private:
    void helper(vector<int>& candidates, vector<int>& path, int index, int sum, vector<vector<int>>& res) {
        if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        int prev = 0;
        for (int i = index; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == prev) continue;
            path.push_back(candidates[i]);
            helper(candidates, path, i + 1, sum - candidates[i], res);
            path.pop_back();
            prev = candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(candidates, path, 0, target, res);
        return res;
    }
};
