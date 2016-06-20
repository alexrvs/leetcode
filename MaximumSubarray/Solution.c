int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        sum = sum > 0 ? sum : 0;
        sum += nums[i];
        max = max > sum ? max : sum;
    }
    return max;
}
