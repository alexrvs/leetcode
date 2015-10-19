class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) return 0;
        int maxProfit = 0;
        int minPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            profit = prices[i] - minPrice;
            if (maxProfit < profit) maxProfit = profit;
        }
        return maxProfit;
    }
};
