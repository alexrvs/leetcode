class Solution {
private:
    int calStep(int limit, long start, long end) {
        int res = 0;
        while (start <= limit) {
            if (limit + 1 < end) {
                res += limit + 1 - start;
            } else {
                res += end - start;
            }
            start *= 10;
            end *= 10;
        }
        return res;
    }
    
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            int step = calStep(n, cur, cur + 1);
            if (step <= k) {
                k -= step;
                cur += 1;
            } else {
                k -= 1;
                cur *= 10;
            }
        }
        return cur;
    }
};