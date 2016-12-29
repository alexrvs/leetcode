public class Solution {
    public int maxProfit(int k, int[] prices) {
        int size = prices.length;
        if (k >= size / 2) {
            int res = 0;
            for (int i = 1; i < size; i++) {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0) res += diff;
            }
            return res;
        }
        
        int[][] dp = new int[k + 1][size];
        for (int i = 1; i <= k; i++) {
            int tmp = -prices[0];
            for (int j = 1; j < size; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], prices[j] + tmp);
                tmp = Math.max(tmp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][size - 1];
    }
}