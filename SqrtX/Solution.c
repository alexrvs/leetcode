int mySqrt(int x) {
    int l = 0;
    int r = x;
    int m = 0;
    if (x < 2) return x;
    while (l < r) {
        m = l + (r - l) / 2;
        if (m <= x / m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l - 1;
}
