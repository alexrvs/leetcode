int hammingDistance(int x, int y) {
    int mask = 0x1;
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ( ((x & mask) ^ (y & mask)) != 0) cnt++;
        x >>= 1;
        y >>= 1;
    }
    return cnt;
}