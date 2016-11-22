class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int h = grid.size();
        if (h == 0) return res;
        int w = grid[0].size();
        if (w == 0) return res;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0) res++;
                    if (i == h - 1 || grid[i + 1][j] == 0) res++;
                    if (j == 0 || grid[i][j - 1] == 0) res++;
                    if (j == w - 1 || grid[i][j + 1] == 0) res++;
                }
            }
        }
        return res;
    }
};