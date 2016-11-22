int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int res = 0;
    int h = gridRowSize;
    if (h == 0) return res;
    int w = gridColSize;
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