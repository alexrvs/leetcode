/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*) malloc(2 * sizeof(int));
    int n = numsSize;
    int l = 0;
    int r = n;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l == n || nums[l] != target) {
        res[0] = -1;
        res[1] = -1;
        *returnSize = 2;
        return res;
    }
    res[0] = l;
    l = 0;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    res[1] = l - 1;
    *returnSize = 2;
    return res;
}
