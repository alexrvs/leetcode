int search(int* seq, int l, int r, int target) {
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (seq[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l - 1;
}

int lengthOfLIS(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 1) return 0;
    int* seq = (int*) malloc(n * sizeof(int));
    memset(seq, 0, n * sizeof(int));
    int seqLen = 0;
    for (int i = 0; i < n; i++) {
        int pos = search(seq, 0, seqLen, nums[i]) + 1;
        seq[pos] = nums[i];
        if (pos == seqLen) {
            seqLen = pos + 1;
        }
    }
    return seqLen;
}
