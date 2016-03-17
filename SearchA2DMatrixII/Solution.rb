def search_row(row, target)
    l = 0
    r = row.length
    while l < r do
        m = l + (r - l) / 2
        if row[m] < target then
            l = m + 1
        elsif row[m] == target then
            return true
        else
            r = m
        end
    end
    return false
end

# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
    l = 0
    r = matrix.length
    while l < r do
        m = l + (r - l) / 2
        if matrix[m][0] <= target then
            l = m + 1
        else
            r = m
        end
    end
    (l - 1).downto(0) do | i |
        return true if search_row(matrix[i], target)
    end
    return false
end
