/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = 1;
    for (int i = 0; i < n; i++) {
        *returnSize <<= 1;
    }
    int* res = (int*) malloc(*returnSize * sizeof(int));
    if (n == 0) {
        res[0] = 0;
        return res;
    }
    int num = 1;
    for (int i = 1; i < n; i++) {
        num <<= 1;
        num |= 0x01;
    }
    int mask = 1;
    int idx = 0;
    for (int i = 0; i <= num; i++) {
        if (i < 2) res[i] = i;
        else {
            if (i == mask << 1) {
                mask <<= 1;
                idx = i - 1;
            }
            res[i] = mask ^ res[idx--];
        }
    }
    return res;
}
