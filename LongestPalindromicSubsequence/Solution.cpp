class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 1));
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                if (s[i] == s[j]) {
                    if (i + 1 <= j - 1) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = 2;
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][size - 1];
    }
};