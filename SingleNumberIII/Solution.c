/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];
    }
    x &= -x;
    *returnSize = 2;
    int* res = (int*) malloc(2 * sizeof(int));
    memset(res, 0, 2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & x) == 0) {
            res[0] ^= nums[i];
        } else {
            res[1] ^= nums[i];
        }
    }
    return res;
}
