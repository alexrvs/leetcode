int maxProfit(int k, int* prices, int pricesSize) {
    int res = 0;
    int diff = 0;
    if (k >= pricesSize / 2) {
        for (int i = 1; i < pricesSize; i++) {
            diff = prices[i] - prices[i - 1];
            if (diff > 0) res += diff;
        }
        return res;
    }
    
    int** dp = (int**) malloc((k + 1) * sizeof(int*));
    for (int i = 0; i <= k; i++) {
        dp[i] = (int*) malloc(pricesSize * sizeof(int));
        memset(dp[i], 0, pricesSize * sizeof(int));
        if (i > 0) {
            diff = dp[i][0] - prices[0];
            for (int j = 1; j < pricesSize; j++) {
                dp[i][j] = dp[i][j - 1];
                if (dp[i][j - 1] < prices[j] + diff) {
                    dp[i][j] = prices[j] + diff;
                }
                if (dp[i - 1][j - 1] - prices[j] > diff) {
                    diff = dp[i - 1][j - 1] - prices[j];
                }
            }
        }
    }
    res = dp[k][pricesSize - 1];
    for (int i = 0; i <= k; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}