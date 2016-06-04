class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix[0].size();
        vector<vector<int> > dp(r + 1, vector<int>(c + 1, 0));
        int m = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    m = max(m, dp[i][j]);
                }
            }
        }
        return m * m;
    }
};
