class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if (row == 0) return 0;
        int col = dungeon[0].size();
        if (col == 0) return 0;
        vector<vector<int> > dp(row, vector<int>(col, 0));
        int hp = 1 - dungeon[row - 1][col - 1];
        dp[row - 1][col - 1] = hp > 1 ? hp : 1;
        for (int i = row - 2; i >= 0; i--) {
            hp = dp[i + 1][col - 1] - dungeon[i][col - 1];
            dp[i][col - 1] = hp > 1 ? hp : 1;
        }
        for (int j = col - 2; j >= 0; j--) {
            hp = dp[row - 1][j + 1] - dungeon[row - 1][j];
            dp[row - 1][j] = hp > 1 ? hp : 1;
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = col - 2; j >= 0; j--) {
                int righthp = dp[i][j + 1] - dungeon[i][j];
                if (righthp < 1) righthp = 1;
                int downhp = dp[i + 1][j] - dungeon[i][j];
                if (downhp < 1) downhp = 1;
                dp[i][j] = righthp < downhp ? righthp : downhp;
            }
        }
        return dp[0][0];
    }
};