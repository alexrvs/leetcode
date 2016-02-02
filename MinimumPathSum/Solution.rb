# @param {Integer[][]} grid
# @return {Integer}
def min_path_sum(grid)
    h = grid.length
    return 0 if h == 0
    w = grid[0].length
    1.upto(h - 1) do | i |
        grid[i][0] += grid[i - 1][0]
    end
    1.upto(w - 1) do | j |
        grid[0][j] += grid[0][j - 1]
    end
    1.upto(h - 1) do | i |
        1.upto(w - 1) do | j |
            if grid[i - 1][j] < grid[i][j - 1] then
                grid[i][j] += grid[i - 1][j]
            else
                grid[i][j] += grid[i][j - 1]
            end
        end
    end
    return grid[h - 1][w - 1]
end
