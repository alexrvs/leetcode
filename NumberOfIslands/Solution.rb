def markVisited(grid, i, j)
    r = grid.length
    return if r == 0
    c = grid[0].length
    grid[i][j] = '0'
    pos = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    pos.each do |p|
        ip = i + p[0]
        jp = j + p[1]
        if 0 <= ip && ip < r && grid[ip][j] == '1'
            markVisited(grid, ip, j)
        end
        if 0 <= jp && jp < c && grid[i][jp] == '1'
            markVisited(grid, i, jp)
        end
    end
end

# @param {Character[][]} grid
# @return {Integer}
def num_islands(grid)
    num = 0
    r = grid.length
    return 0 if r == 0
    c = grid[0].length
    i = 0
    while i < r do
        j = 0
        while j < c do
            if grid[i][j] == '1'
                num += 1
                markVisited(grid, i, j)
            end
            j += 1
        end
        i += 1
    end
    return num
end
