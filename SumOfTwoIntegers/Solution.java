public class Solution {
    public int getSum(int a, int b) {
        int s = 0;
        int c = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            s |= ( (a & mask) ^ (b & mask) ^ (c & mask));
            c = ( ((a & mask) & (b & mask)) | ((a & mask) & (c & mask)) | ((b & mask) & (c & mask)) );
            c <<= 1;
            mask <<= 1;
        }
        return s;
    }
}