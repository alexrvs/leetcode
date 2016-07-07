class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        int bi = 0;
        int bSize = b.size();
        a %= 1337;
        while (bi < bSize) {
            if (b[bSize - 1] % 2 == 1) {
                res = res * a % 1337;
                b[bSize - 1] -= 1;
            } else {
                for (int i = bi; i < bSize; i++) {
                    if (i < bSize - 1) { b[i + 1] += 10 * (b[i] % 2); }
                    b[i] >>= 1;
                }
                a = a * a % 1337;
            }
            if (b[bi] == 0) bi++;
        }
        return res;
    }
};
