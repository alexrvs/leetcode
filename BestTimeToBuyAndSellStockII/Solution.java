public class Solution {
    public int maxProfit(int[] prices) {
        int size = prices.length;
        if (size < 2) return 0;
        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i - 1] < prices[i]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
}
