/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    let res = 0;
    let h = grid.length;
    if (h === 0) return res;
    let w = grid[0].length;
    if (w === 0) return res;
    for (let i = 0; i < h; i++) {
        for (let j = 0; j < w; j++) {
            if (grid[i][j] == 1) {
                if (i === 0 || grid[i - 1][j] === 0) res++;
                if (i == h - 1 || grid[i + 1][j] === 0) res++;
                if (j === 0 || grid[i][j - 1] === 0) res++;
                if (j == w - 1 || grid[i][j + 1] === 0) res++;
            }
        }
    }
    return res;
};