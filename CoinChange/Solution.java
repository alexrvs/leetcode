public class Solution {
    public int coinChange(int[] coins, int amount) {
        int max = amount + 1;
        int n = coins.length;
        int[] cnts = new int[max];
        for (int i = 1; i < max; i++) cnts[i] = max;
        for (int i = 0; i < n; i++) {
            if (coins[i] < max) cnts[coins[i]] = 1;
        }
        for (int i = 1; i < max; i++) {
            for (int j = 0; j < n; j++) {
                int prev = i - coins[j];
                if (prev >= 1 && cnts[prev] + 1 < cnts[i]) {
                    cnts[i] = cnts[prev] + 1; 
                }
            }
        }
        if (cnts[amount] == max) return -1;
        return cnts[amount];
    }
}
