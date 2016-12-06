class Solution {
public:
    int numDistinct(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector<vector<int> > dp(tSize + 1, vector<int>(sSize + 1, 0));
        for (int i = 0; i <= sSize; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= tSize; i++) {
            for (int j = 1; j <= sSize; j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[tSize][sSize];
    }
};