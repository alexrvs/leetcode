int removeElement(int* nums, int numsSize, int val) {
    int cur = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[cur++] = nums[i];
        }
    }
    return cur;
}
