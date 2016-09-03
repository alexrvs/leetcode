int guess(int num);

int guessNumber(int n) {
    int l = 1;
    int r = n;
    int m = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (guess(m) > 0) {
            l = m + 1;
        } else if (guess(m) == 0) {
            return m;
        } else {
            r = m - 1;
        }
    }
    return m;
}
