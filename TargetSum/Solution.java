public class Solution {
    int cnt;
    
    private void helper(int[] nums, int idx, int sum, int target) {
        if (idx >= nums.length) {
            if (sum == target) cnt++;
            return;
        }
        helper(nums, idx + 1, sum + nums[idx], target);
        helper(nums, idx + 1, sum - nums[idx], target);
        return;
    }
    
    public int findTargetSumWays(int[] nums, int S) {
        cnt = 0;
        helper(nums, 0, 0, S);
        return cnt;
    }
}