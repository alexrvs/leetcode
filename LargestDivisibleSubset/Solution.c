static int comp(void* a, void* b) {
    return *((int*)a) - *((int*)b);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    int* steps = (int*) malloc(numsSize * sizeof(int));
    int* idx = (int*) malloc(numsSize * sizeof(int));
    int maxSteps = 0;
    int maxIdx = 0;
    for (int i = 0; i < numsSize; i++) {
        steps[i] = 1;
        idx[i] = i;
        if (maxSteps < steps[i]) {
            maxSteps = steps[i];
            maxIdx = i;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                steps[i] = steps[j] + 1;
                idx[i] = j;
                if (maxSteps < steps[i]) {
                    maxSteps = steps[i];
                    maxIdx = i;
                }
                break;
            }
        }
    }
    *returnSize = maxSteps;
    int* res = (int*) malloc(maxSteps * sizeof(int));
    while (maxSteps-- != 0) {
        res[maxSteps] = nums[maxIdx];
        maxIdx = idx[maxIdx];
    }
    free(steps);
    free(idx);
    return res;
}
