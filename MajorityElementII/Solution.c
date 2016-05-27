/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int n1, n2, c1, c2;
    int* res = (int*) malloc(2 * sizeof(int));
    c1 = c2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (c1 > 0 && n1 == nums[i]) {
            c1++;
            continue;
        }
        if (c2 > 0 && n2 == nums[i]) {
            c2++;
            continue;
        }
        if (c1 == 0) {
            n1 = nums[i];
            c1 = 1;
            continue;
        }
        if (c2 == 0) {
            n2 = nums[i];
            c2 = 1;
            continue;
        }
        c1--;
        c2--;
    }
    *returnSize = 0;
    if (c1 > 0) {
        c1 = 0;
        for (int i = 0; i < numsSize; i++) {
            if (n1 == nums[i]) c1++;
        }
        if (c1 > numsSize / 3) {
            res[(*returnSize)++] = n1;
        }
    }
    if (c2 > 0) {
        c2 = 0;
        for (int i = 0; i < numsSize; i++) {
            if (n2 == nums[i]) c2++;
        }
        if (c2 > numsSize / 3) {
            res[(*returnSize)++] = n2;
        }
    }
    return res;
}
