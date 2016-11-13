bool search(int* nums, int numsSize, int target) {
    int size = numsSize;
    int l = 0;
    int r = size - 1;
    int m = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (nums[m] == target) return true;
        if (nums[l] < nums[m]) {
            if (nums[l] <= target && target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else if (nums[l] > nums[m]) {
            if (nums[m] < target && target <= nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else {
            l++;
        }
    }
    return false;
}