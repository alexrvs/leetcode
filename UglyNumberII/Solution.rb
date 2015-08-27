# @param {Integer} n
# @return {Integer}
def nth_ugly_number(n)
    ugly_nums = [1]
    i2 = i3 = i5 = 0
    while ugly_nums.length < n
        num2 = ugly_nums[i2]*2
        num3 = ugly_nums[i3]*3
        num5 = ugly_nums[i5]*5
        min_num = [num2, num3, num5].min
        ugly_nums << min_num
        i2 += 1 if min_num == num2
        i3 += 1 if min_num == num3
        i5 += 1 if min_num == num5
    end
    return ugly_nums.last
end
