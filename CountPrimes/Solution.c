int countPrimes(int n) {
    if (n < 3) return 0;
    int* isPrime = (int*) malloc(n * sizeof(int));
    memset(isPrime, 0, n * sizeof(int));
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] == 0) {
            int step = 2 * i;
            while (step < n) {
                isPrime[step] = 1;
                step += i;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i] == 0) cnt++;
    }
    free(isPrime);
    return cnt;
}
