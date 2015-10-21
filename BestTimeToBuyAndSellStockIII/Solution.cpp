class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) return 0;
        vector<int> forward(size, 0);
        vector<int> backward(size, 0);
        int minPrice = prices[0];
        int maxProfit = 0;
        int profit = 0;
        for (int i = 0; i < size; i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            profit = prices[i] - minPrice;
            if (maxProfit < profit) maxProfit = profit;
            forward[i] = maxProfit;
        }
        int maxPrice = prices[size - 1];
        maxProfit = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (maxPrice < prices[i]) maxPrice = prices[i];
            profit = maxPrice - prices[i];
            if (maxProfit < profit) maxProfit = profit;
            backward[i] = maxProfit;
        }
        maxProfit = 0;
        for (int i = 0; i < size; i++) {
            profit = forward[i] + backward[i];
            if (maxProfit < profit) maxProfit = profit;
        }
        return maxProfit;
    }
};
