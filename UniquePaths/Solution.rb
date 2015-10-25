# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def unique_paths(m, n)
    r = Array.new(n, 0)
    p = Array.new(m, r)
    i = 0
    while i < m do
        p[i][0] = 1
        i += 1
    end
    i = 0
    while i < n do
        p[0][i] = 1
        i += 1
    end
    p.each_with_index do |r, i|
        r.each_with_index do |c, j|
            p[i][j] = p[i - 1][j] + p[i][j - 1] if i > 0 && j > 0
        end
    end
    return p[m - 1][n - 1]
end
