class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        vector<int> cnts(max, max);
        cnts[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            if (coins[i] < max) {
                cnts[coins[i]] = 1;
            }
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                int prev = i - coins[j];
                if (prev >= 1) {
                    cnts[i] = (cnts[i] < cnts[prev] + 1 ? cnts[i] : cnts[prev] + 1);
                }
            }
        }
        if (cnts[amount] == max) return -1;
        return cnts[amount];
    }
};
