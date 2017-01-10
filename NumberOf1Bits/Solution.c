int hammingWeight(uint32_t n) {
    int num = 0;
    int mask = 0x1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) num++;
        mask <<= 1;
    }
    return num;
}