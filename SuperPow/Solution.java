public class Solution {
    private int helper(int e, int p) {
        int r = 1;
        e %= 1337;
        while (p > 0) {
            if ((p & 1) == 1) {
                r = r * e % 1337;
            }
            p >>= 1;
            e = e * e % 1337;
        }
        return r;
    }

    public int superPow(int a, int[] b) {
        int size = b.length;
        int r = 1;
        a %= 1337;
        for (int i = size - 1; i >= 0; i--) {
            r = r * helper(a, b[i]) % 1337;
            a = helper(a, 10);
        }
        return r;
    }
}
