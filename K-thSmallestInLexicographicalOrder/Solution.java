public class Solution {
    private int calStep(int limit, long start, long end) {
        int step = 0;
        while (start <= limit) {
            step += Math.min(limit + 1, end) - start;
            start *= 10;
            end *= 10;
        }
        return step;
    }
    
    public int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            int step = calStep(n, cur, cur + 1);
            if (k >= step) {
                cur += 1;
                k -= step;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
}