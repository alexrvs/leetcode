/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var h = grid.length;
    if (h === 0) return 0;
    var w = grid[0].length;
    var i = 0;
    var j = 0;
    for (i = 1; i < h; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (j = 1; j < w; j++) {
        grid[0][j] += grid[0][j - 1];
    }
    for (i = 1; i < h; i++) {
        for (j = 1; j < w; j++) {
            grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1]);
        }
    }
    return grid[h - 1][w - 1];
};
