public class Solution {
    public int maxProfit(int[] prices) {
        int l = prices.length;
        if (l < 2) return 0;
        int[] forward = new int[l];
        int[] backward = new int[l];
        int maxProfit = 0;
        int minPrice = prices[0];
        int profit = 0;
        for (int i = 0; i < l; i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            profit = prices[i] - minPrice;
            if (maxProfit < profit) maxProfit = profit;
            forward[i] = maxProfit;
        }
        maxProfit = 0;
        int maxPrice = prices[l - 1];
        for (int i = l - 1; i >= 0; i--) {
            if (maxPrice < prices[i]) maxPrice = prices[i];
            profit = maxPrice - prices[i];
            if (maxProfit < profit) maxProfit = profit;
            backward[i] = maxProfit;
        }
        maxProfit = 0;
        for (int i = 0; i < l; i++) {
            profit = forward[i] + backward[i];
            if (maxProfit < profit) maxProfit = profit;
        }
        return maxProfit;
    }
}
