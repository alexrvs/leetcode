bool helper(int* nums, int numsSize, int idx, int sum, int target) {
    if (idx >= numsSize) return false;
    sum += nums[idx];
    if (sum == target) return true;
    if (sum < target && helper(nums, numsSize, idx + 1, sum, target)) return true;
    sum -= nums[idx];
    if (sum < target && helper(nums, numsSize, idx + 1, sum, target)) return true;
    return false;
}

bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) return false;
    return helper(nums, numsSize, 0, 0, sum / 2);
}