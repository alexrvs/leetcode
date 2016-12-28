uint32_t reverseBits(uint32_t n) {
    uint32_t mask = 0x80000000;
    uint32_t res = 0;
    while (n > 0) {
        if (n & 0x00000001) {
            res |= mask;
        }
        n >>= 1;
        mask >>= 1;
    }
    return res;
}