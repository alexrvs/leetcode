struct NumArray {
    int* m_nums;
    int* m_sums;
    int size;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* numArray = (struct NumArray*) malloc(sizeof(struct NumArray));
    numArray->size = numsSize;
    numArray->m_nums = nums;
    numArray->m_sums = (int*) malloc(numsSize * sizeof(int));
    numArray->m_sums[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        numArray->m_sums[i] = numArray->m_sums[i - 1] + nums[i - 1];
    }
    return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return numArray->m_sums[j] - numArray->m_sums[i] + numArray->m_nums[j];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->m_sums);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
