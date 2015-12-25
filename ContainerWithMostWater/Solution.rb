# @param {Integer[]} height
# @return {Integer}
def max_area(height)
    l = height.length
    i = 0
    j = l - 1
    area = 0
    max = 0
    while i < j do
        h = height[i] if height[i] < height[j]
        h = height[j] if height[i] >= height[j]
        area = h * (j - i)
        if area > max then
            max = area
        end
        if height[i] < height[j] then
            i += 1
        else
            j -= 1
        end
    end
    return max
end
