int firstMissingPositive(int* nums, int numsSize) {
    int size = numsSize;
    int cur = 0;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        cur = nums[i];
        while (cur >= 1 && cur <= size && nums[cur - 1] != cur) {
            tmp = nums[cur - 1];
            nums[cur - 1] = cur;
            cur = tmp;
        }
    }
    for (int i = 0; i < size; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}
