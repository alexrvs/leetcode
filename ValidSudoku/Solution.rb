# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)
    l = board.length
    rowNums = Array.new(l, 0)
    colNums = Array.new(l, 0)
    gridNums = Array.new(l, 0)
    l.times do |i| 
        l.times do |j|
            g = i / 3 * 3 + j / 3
            if board[i][j] != '.' then
                val = 1 << (board[i][j].to_i - 1)
                if rowNums[i] & val != 0 || colNums[j] & val != 0 || gridNums[g] & val != 0 then
                    return false
                else
                    rowNums[i] |= val
                    colNums[j] |= val
                    gridNums[g] |= val
                end
            end
        end
    end
    return true
end
