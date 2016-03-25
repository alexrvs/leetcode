class Solution {
private:
    void helper(vector<int>& candidates, vector<int>& path, int index, int sum, int target, vector<vector<int>>& res) {
        if (sum > target) return;
        if (sum == target) { 
            res.push_back(path); return; }
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            helper(candidates, path, i, sum + candidates[i], target, res);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        helper(candidates, path, 0, 0, target, res);
        return res;
    }
};
