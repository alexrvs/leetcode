# @param {Integer} row_index
# @return {Integer[]}
def get_row(row_index)
    row = Array.new(row_index + 1, 0)
    row[0] = 1
    1.upto(row_index) do | i |
        i.downto(1) do | j |
            row[j] += row[j - 1]
        end
    end
    return row
end
