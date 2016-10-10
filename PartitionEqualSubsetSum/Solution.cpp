class Solution {
private:
    bool helper(vector<int>& nums, int idx, int sum, int target) {
        if (idx >= nums.size()) return false;
        sum += nums[idx];
        if (sum == target) return true;
        if (sum < target && helper(nums, idx + 1, sum, target)) return true;
        sum -= nums[idx];
        if (sum < target && helper(nums, idx + 1, sum, target)) return true;
        return false;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 0) {
            if (helper(nums, 0, 0, sum / 2) == true) return true;
        }
        return false;
    }
};