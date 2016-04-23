bool isPowerOfTwo(int n) {
    int cnt = 0;
    while(n > 0) {
        if (n & 0x0001) cnt++;
        n >>= 1;
    }
    if (cnt == 1) return true;
    return false;
}
