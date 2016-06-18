def is_live(board, i, j, row, col)
    cnt = 0
    -1.upto(1) do | r |
        -1.upto(1) do | c |
            if !(r == 0 && c == 0) &&
               i + r >= 0 && i + r < row &&
               j + c >= 0 && j + c < col &&
               board[i + r][j + c] & 0x0001 == 1 then
                cnt += 1
            end
        end
    end
    return true if cnt == 2 && board[i][j] == 1
    return true if cnt == 3
    return false
end

# @param {Integer[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def game_of_life(board)
    r = board.length
    return if r == 0
    c = board[0].length
    r.times do | i |
        c.times do | j |
            if is_live(board, i, j, r, c) then
                board[i][j] += 2
            end
        end
    end
    r.times do | i |
        c.times do | j |
            board[i][j] >>= 1
        end
    end
end
