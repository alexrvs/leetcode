int missingNumber(int* nums, int numsSize) {
    int x = nums[0];
    for (int i = 1; i < numsSize; i++) {
        x ^= nums[i];
    }
    for (int i = 0; i <= numsSize; i++) {
        x ^= i;
    }
    return x;
}

