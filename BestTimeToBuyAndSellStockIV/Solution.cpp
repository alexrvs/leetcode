class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (k >= size / 2) {
            int res = 0;
            for (int i = 1; i < size; i++) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        
        vector<vector<int> > dp(k + 1, vector<int>(size, 0));
        for (int i = 1; i <= k; i++) {
            int tmp = -prices[0];
            for (int j = 1; j < size; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + tmp);
                tmp = max(tmp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][size - 1];
    }
};