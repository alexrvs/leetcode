int numTrees(int n) {
    int * num = (int *) malloc((n + 1) * sizeof(int));
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            num[i] += num[j - 1] * num[i - j];
        }
    }
    return num[n];
}
