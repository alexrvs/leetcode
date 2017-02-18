/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) return NULL;
    *returnSize = numsSize;
    int* res = (int*) malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        res[i] = -1;
        for (int j = 1; j < numsSize; j++) {
            int idx = (i + j) % numsSize;
            if (nums[i] < nums[idx]) {
                res[i] = nums[idx];
                break;
            }
        }
    }
    return res;
}