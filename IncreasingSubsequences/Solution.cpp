class Solution {
private:
    void helper(vector<vector<int>>& res, vector<int>& l, vector<int>& nums, int idx) {
        if (l.size() > 1) {
            res.push_back(vector<int>(l));
        }
        set<int> used;
        for (int i = idx; i < nums.size(); i++) {
            if (idx > 0 && nums[idx - 1] > nums[i]) continue;
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            l.push_back(nums[i]);
            helper(res, l, nums, i + 1);
            l.pop_back();
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> l;
        helper(res, l, nums, 0);
        return res;
    }
};