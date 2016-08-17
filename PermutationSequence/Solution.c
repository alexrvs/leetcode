void permuteUnique(char* res, int* used, int size, int n, int k) {
    int resIdx = size - n;
    if (k == 0) {
        for (int i = 0; i < size; i++) {
            if (used[i] != 1) {
                res[resIdx++] = '0' + i + 1;
            }
        }
        return;
    }
    int temp = 1;
    int i = 1;
    while (i < n) {
        temp *= i++;
    }
    int idx = k / temp;
    for (int i = 0; i < size; i++) {
        if (used[i] != 1 && idx-- == 0) {
            res[resIdx] = '0' + i + 1;
            used[i] = 1;
        }
    }
    k %= temp;
    permuteUnique(res, used, size, n - 1, k);
    return;
}

char* getPermutation(int n, int k) {
    int* used = (int*) malloc(n * sizeof(int));
    memset(used, 0, n * sizeof(int));
    char* res = (char*) malloc((n + 1) * sizeof(char));
    memset(res, 0, (n + 1) * sizeof(char));
    permuteUnique(res, used, n, n, k - 1);
    free(used);
    return res;
}
