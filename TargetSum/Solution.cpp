class Solution {
private:
    void helper(vector<int>& nums, int idx, int sum, int target, int& cnt) {
        if (idx >= nums.size()) {
            if (sum == target) cnt++;
            return;
        }
        helper(nums, idx + 1, sum + nums[idx], target, cnt);
        helper(nums, idx + 1, sum - nums[idx], target, cnt);
        return;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0;
        helper(nums, 0, 0, S, cnt);
        return cnt;
    }
};