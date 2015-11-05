# @param {Integer[][]} triangle
# @return {Integer}
def minimum_total(triangle)
    triangle.each_with_index do |row, i|
        if i > 0
            row.each_with_index do |w, j|
                if j == 0
                    triangle[i][j] += triangle[i - 1][j]
                elsif j == i
                    triangle[i][j] += triangle[i - 1][j - 1]
                else
                    tmp = triangle[i - 1][j]
                    tmp = triangle[i - 1][j - 1] if tmp > triangle[i - 1][j - 1]
                    triangle[i][j] += tmp
                end
            end
        end
    end
    return triangle.last.min
end
