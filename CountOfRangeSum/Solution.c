int mergeAndCount(long* sums, long* buff, int start, int end, int lower, int upper) {
    if (end - start <= 1) return 0;
    int mid = start + (end - start) / 2;
    int cnt = mergeAndCount(sums, buff, start, mid, lower, upper) + mergeAndCount(sums, buff, mid, end, lower, upper);
    int lowerIdx = mid, upperIdx = mid, tempIdx = mid;
    for (int i = start, bi = 0; i < mid; i++, bi++) {
        while (lowerIdx < end && sums[lowerIdx] - sums[i] < lower) lowerIdx++;
        while (upperIdx < end && sums[upperIdx] - sums[i] <= upper) upperIdx++;
        while (tempIdx < end && sums[tempIdx] < sums[i]) buff[bi++] = sums[tempIdx++];
        cnt += upperIdx - lowerIdx;
        buff[bi] = sums[i];
    }
    memcpy(sums + start, buff, (tempIdx - start) * sizeof(long));
    return cnt;
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long* sums = (long* ) malloc((numsSize + 1) * sizeof(long));
    long* buff = (long* ) malloc((numsSize + 1) * sizeof(long));
    sums[0] = 0;
    int cnt = mergeAndCount(sums, buff, 0, numsSize + 1, lower, upper);
    return cnt;
}
