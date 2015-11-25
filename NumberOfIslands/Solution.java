public class Solution {
    private void markVisited(char[][] grid, int i, int j) {
        grid[i][j] = '0';
        int r = grid.length;
        if (r == 0) return;
        int c = grid[0].length;
        for (int a = -1; a <= 1; a += 2) {
            int ia = i + a;
            if (0 <= ia && ia < r && grid[ia][j] == '1') markVisited(grid, ia, j);
        }
        for (int b = -1; b <= 1; b += 2) {
            int jb = j + b;
            if (0 <= jb && jb < c && grid[i][jb] == '1') markVisited(grid, i, jb);
        }
    }

    public int numIslands(char[][] grid) {
        int num = 0;
        int r = grid.length;
        if (r == 0) return num;
        int c = grid[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    num++;
                    markVisited(grid, i, j);
                }
            }
        }
        return num;
    }
}
