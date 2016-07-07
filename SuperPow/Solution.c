int helper(int e, int p) {
    int res = 1;
    e = e % 1337;
    while (p > 0) {
        if (p % 2 == 1) {
            res = ((res * e) % 1337);
        }
        p >>= 1;
        e = ((e * e) % 1337);
    }
    return res;
}

int superPow(int a, int* b, int bSize) {
    int res = 1;
    for (int i = bSize - 1; i >= 0; i--) {
        res = ((res * helper(a, b[i])) % 1337);
        a = helper(a, 10);
    }
    return res;
}
