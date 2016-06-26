class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return true;
        int l = 1;
        int r = num / 2;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (m < num / m) l = m + 1;
            else r = m;
        }
        return (l == num / l && num % l == 0);
    }
};
