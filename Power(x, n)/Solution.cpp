class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        double remain = 1.0;
        double cur = x;
        if (n < 0) {
            n += 1;
            n = -n;
            cur = 1.0 / cur;
            remain *= cur;
            return remain * myPow(cur, n);
        }
        while (n > 1) {
            if (n % 2 != 0) {
                remain *= cur;
            }
            cur *= cur;
            n >>= 1;
        }
        return cur * remain;
    }
};
