public class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;
        int l = 0;
        int r = x;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (m <= x / m) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    }
}
