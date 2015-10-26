# @param {Integer[]} height
# @return {Integer}
def trap(height)
    size = height.length
    forward = Array.new(size, 0)
    backward = Array.new(size, 0)
    maxH = 0
    height.each_with_index do |h, i|
        maxH = h if maxH < h
        forward[i] = maxH - h
    end
    maxH = 0
    sum = 0
    height.reverse.each_with_index do |h, j|
        i = size - 1 - j
        maxH = h if maxH < h
        backward[i] = maxH - h
        sum += forward[i] if forward[i] < backward[i]
        sum += backward[i] unless forward[i] < backward[i]
    end
    return sum
end
