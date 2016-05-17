double myPow(double x, int n) {
    double remain = 1.0;
    double cur = x;
    if (n == 0) return 1;
    if (n < 0) {
        n += 1;
        n = -n;
        cur = 1.0 / x;
        remain *= cur;
        return remain * myPow(cur, n);
    }
    while (n > 1) {
        if (n % 2 == 1) remain *= cur;
        cur *= cur;
        n >>= 1;
    }
    return remain * cur;
}
