void markVisited(char** grid, int i, int r, int j, int c) {
    grid[i][j] = '0';
    for (int a = -1; a <= 1; a += 2) {
        int ia = i + a;
        if (0 <= ia && ia < r && grid[ia][j] == '1') markVisited(grid, ia, r, j, c);
    }
    for (int b = -1; b <= 1; b += 2) {
        int jb = j + b;
        if (0 <= jb && jb < c && grid[i][jb] == '1') markVisited(grid, i, r, jb, c);
    }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int num = 0;
    int r = gridRowSize;
    if (r == 0) return 0;
    int c = gridColSize;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                num++;
                markVisited(grid, i, r, j, c);
            }
        }
    }
    return num;
}