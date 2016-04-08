# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def rotate(matrix)
    l = matrix.length
    h = l / 2
    w = h
    w += 1 if l % 2 != 0
    h.times do | i |
        w.times do | j |
            t = matrix[i][j]
            matrix[i][j] = matrix[l - 1 - j][i]
            matrix[l - 1 - j][i] = matrix[l - 1 - i][l - 1 - j]
            matrix[l - 1 - i][l - 1 - j] = matrix[j][l - 1 - i]
            matrix[j][l - 1 - i] = t
        end
    end
end
