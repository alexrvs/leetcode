/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int resSize = numsSize - k + 1;
    int* res = (int*) malloc(resSize * sizeof(int));
    if (numsSize == 0) {
        *returnSize = 0;
        return res;
    }
    int* can = (int*) malloc(k * sizeof(int));
    int first = 0;
    int last = -1;
    int size = 0;
    int r = 0;
    for (int i = 0; i < numsSize; i++) {
        while (size != 0 && can[first] < i - k + 1) {
            first = (first + 1) % k;
            size--;
        }
        while (size != 0 && nums[can[last]] < nums[i]) {
            last = (last - 1 + k) % k;
            size--;
        }
        last = (last + 1) % k;
        can[last] = i;
        size++;
        if (i >= k - 1) {
            res[r++] = nums[can[first]];
        }
    }
    free(can);
    *returnSize = resSize;
    return res;
}
