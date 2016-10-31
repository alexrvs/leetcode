class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return 1;
        int m = 0;
        int l = 1;
        int r = (n + 1) / 2;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (m + 1 <= (n / m) * 2) l = m + 1;
            else r = m - 1;
        }
        cout << l << endl;
        int sum = (l % 2 == 0) ? (l / 2) * (l + 1) : l * ((l + 1) / 2);
        if (sum > n) return l - 1;
        return l;
    }
};