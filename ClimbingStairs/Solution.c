int climbStairs(int n) {
    int* cnts = (int*) malloc((n + 1) * sizeof(int));
    int res = 0;
    cnts[0] = 0;
    if (n >= 1) cnts[1] = 1;
    if (n >= 2) cnts[2] = 2;
    for (int i = 3; i <= n; i++) {
        cnts[i] = cnts[i - 1] + cnts[i - 2];
    }
    res = cnts[n];
    return res;
}
