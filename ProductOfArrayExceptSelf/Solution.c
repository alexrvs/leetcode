/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int size = numsSize;
    *returnSize = size;
    int* res = (int*) malloc(size * sizeof(int));
    res[0] = 1;
    for (int i = 1; i < size; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int prod = 1;
    for (int i = size - 1; i >= 0; i--) {
        res[i] *=  prod;
        prod *= nums[i];
    }
    return res;
}
