static int comp(void* a, void* b) {
    return *((int*) a) - *((int*) b);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res = (int*) malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
        if (nums1[i] == nums2[j]) {
            res[*returnSize] = nums1[i];
            (*returnSize)++;
            while (++i < nums1Size && nums1[i] == nums1[i - 1]);
            while (++j < nums2Size && nums2[j] == nums2[j - 1]);
        } else if (nums1[i] < nums2[j]) {
            while (++i < nums1Size && nums1[i] == nums1[i - 1]);
        } else {
            while (++j < nums2Size && nums2[j] == nums2[j - 1]);
        }
    }
    return res;
}
