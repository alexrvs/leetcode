class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rl = ring.size();
        int kl = key.size();
        vector<vector<int> > dp(kl + 1, vector<int>(rl, 0));
        
        for (int i = kl - 1; i >= 0; i--) {
            for (int j = 0; j < rl; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < rl; k++) {
                    if (key[i] == ring[k]) {
                        int diff = j > k ? j - k : k - j;
                        if (diff > rl - diff) diff = rl - diff;
                        if (dp[i][j] > dp[i + 1][k] + diff) dp[i][j] = dp[i + 1][k] + diff;
                    }
                }
            }
        }
        
        return dp[0][0] + kl;
    }
};