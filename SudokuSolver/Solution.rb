def is_valid(board, a, b)
    r = board.length
    return false if r == 0
    c = board[0].length
    r.times do | i |
        return false if i != a && board[i][b] == board[a][b]
    end
    c.times do | j |
        return false if j != b && board[a][j] == board[a][b]
    end
    x = a / 3 * 3
    y = b / 3 * 3
    0.upto(2) do | i |
        0.upto(2) do | j |
            return false if x + i != a && y + j != b && board[x + i][y + j] == board[a][b]
        end
    end
    return true
end

def dfs(board)
    r = board.length
    return false if r == 0
    c = board[0].length
    r.times do | i |
        c.times do | j |
            if board[i][j] == '.' then
                "123456789".chars.each do | c |
                    board[i][j] = c
                    return true if is_valid(board, i, j) && dfs(board)
                    board[i][j] = '.'
                end
                return false
            end
        end
    end
    return true
end

# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def solve_sudoku(board)
    dfs(board)
end
