var markVisited = function(grid, i, j) {
    var r = grid.length;
    if (r === 0) return;
    var c = grid[0].length;
    grid[i][j] = '0';
    for (var ia = i - 1; ia < i + 2; ia += 2) {
        if (0 <= ia && ia < r && grid[ia][j] == '1') markVisited(grid, ia, j);
    }
    for (var jb = j - 1; jb < j + 2; jb += 2) {
        if (0 <= jb && jb < c && grid[i][jb] == '1') markVisited(grid, i, jb);
    }
}

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    var num = 0;
    var r = grid.length;
    if (r === 0) return num;
    var c = grid[0].length;
    for (var i = 0; i < r; i++) {
        for (var j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                num++;
                markVisited(grid, i, j);
            }
        }
    }
    return num;
};
