class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        unsigned int k = n;
        while (k > 3) {
            cnt++;
            if (k & 1) {
                if (k & 2) k++;
                else k--;
            }
            else k >>= 1;
        }
        return cnt + k - 1;
    }
};
