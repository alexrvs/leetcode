int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    if (n == 0) return 0;
    int* res = (int*) malloc(n * sizeof(int));
    int* idx = (int*) malloc(primesSize * sizeof(int));
    memset(idx, 0, primesSize * sizeof(int));
    res[0] = 1;
    int min = -1;
    int tmp = 0;
    for (int i = 1; i < n; i++) {
        min = -1;
        for (int j = 0; j < primesSize; j++) {
            tmp = primes[j] * res[idx[j]];
            if (min == -1 || min > tmp) min = tmp;
        }
        for (int j = 0; j < primesSize; j++) {
            tmp = primes[j] * res[idx[j]];
            if (tmp == min) idx[j]++;
        }
        res[i] = min;
    }
    int ret = res[n - 1];
    free(res);
    free(idx);
    return ret;
}
