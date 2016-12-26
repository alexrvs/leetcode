int findMin(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int l = 0;
    int r = numsSize - 1;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] > nums[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return nums[r];
}