class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 0x0001;
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (n & mask) num++;
            mask = mask << 1;
        }
        return num;
    }
};
