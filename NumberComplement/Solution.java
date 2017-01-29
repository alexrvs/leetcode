public class Solution {
    public int findComplement(int num) {
        int res = 0;
        int mask = 0x1;
        for (int i = 0; i < 32; i++) {
            if ((mask & num) != 0) res = 1 << (i + 1);
            mask <<= 1;
        }
        return res - 1 - num;
    }
}