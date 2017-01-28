void helper(int* nums, int numsSize, int idx, int sum, int target, int* cnt) {
    if (idx >= numsSize) {
        if (sum == target) *cnt = (*cnt) + 1;
        return;
    }
    helper(nums, numsSize, idx + 1, sum + nums[idx], target, cnt);
    helper(nums, numsSize, idx + 1, sum - nums[idx], target, cnt);
    return;
}

int findTargetSumWays(int* nums, int numsSize, int S) {
    int cnt = 0;
    helper(nums, numsSize, 0, 0, S, &cnt);
    return cnt;
}