int findMin(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int l = 0;
    int r = numsSize - 1;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[r] < nums[m]) {
            l = m + 1;
        } else if (nums[m] < nums[r]) {
            r = m;
        } else {
            if (nums[l] == nums[m]) {
                l++;
                r--;
            } else {
                r = m;
            }
        }
    }
    return nums[r];
}