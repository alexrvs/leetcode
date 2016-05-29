int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int noDupIdx = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[noDupIdx]) {
            nums[++noDupIdx] = nums[i];
        }
    }
    return noDupIdx + 1;
}
