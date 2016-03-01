# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def set_zeroes(matrix)
    r = matrix.length
    return if r == 0
    c = matrix[0].length
    firstRow = 1
    firstCol = 1
    r.times do | i |
        firstCol = 0 if matrix[i][0] == 0
        c.times do | j |
            if matrix[i][j] == 0 then
                matrix[i][0] = 0
                matrix[0][j] = 0
                firtRow = 0 if i == 0
            end
        end
    end
    1.upto(r - 1) do | i |
        1.upto(c - 1) do | j |
            matrix[i][j] = 0 if matrix[i][0] == 0 or matrix[0][j] == 0
        end
    end
    if firstRow == 0 then c.times do | j | matrix[0][j] = 0 end end
    if firstCol == 0 then r.times do | i | matrix[i][0] = 0 end end
end
