class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        int start = 0;
        int diff = A[1] - A[0];
        int cnt = 0;
        for (int i = 2; i <= len; i++) {
            if (i >= len || A[i] - A[i - 1] != diff) {
                int sLen = i - start;
                if (sLen >= 3) {
                    int n = sLen - 2;
                    cnt += (n + 1) * n / 2;
                }
                if (i < len) {
                    start = i - 1;
                    diff = A[i] - A[i - 1];
                }
            }
        }
        return cnt;
    }
};