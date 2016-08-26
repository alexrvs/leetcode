int rob(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 1) {
            int sum = 0;
            if (i - 2 >= 0) sum = nums[i] + nums[i - 2];
            if (i - 3 >= 0) sum = sum > nums[i] + nums[i - 3] ? sum : nums[i] + nums[i - 3];
            nums[i] = sum;
        }
        if (nums[i] > max) max = nums[i];
    }
    return max;
}
