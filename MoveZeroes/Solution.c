void moveZeroes(int* nums, int numsSize) {
    int cur = 0;
    int size = numsSize;
    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            nums[cur++] = nums[i];
        }
    }
    for (; cur < size; cur++) {
        nums[cur] = 0;
    }
    return;
}
