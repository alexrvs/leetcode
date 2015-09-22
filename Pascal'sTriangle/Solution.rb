# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
    res = []
    i = 0
    while i < num_rows
        row = []
        row << 1
        j = 1
        while j < i
            row << (res[i-1][j-1] + res[i-1][j])
            j += 1
        end
        row << 1 if i > 0
        res << row
        i += 1
    end
    return res
end
