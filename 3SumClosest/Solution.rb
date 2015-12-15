# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def three_sum_closest(nums, target)
    closest = 0
    l = nums.length
    return closest if l < 3
    nums.sort!
    closest = nums[0] + nums[1] + nums[2]
    minDist = closest - target if target <= closest
    minDist = target - closest if closest < target
    nums.each_with_index do | ni, i |
        j = i + 1
        k = l - 1
        while j < k do
            sum = nums[i] + nums[j] + nums[k]
            if sum == target then
                return sum
            elsif sum < target then
                if target - sum < minDist then
                    minDist = target - sum
                    closest = sum
                end
                j += 1
            else
                if sum - target < minDist then
                    minDist = sum - target
                    closest = sum
                end
                k -= 1
            end
        end
    end
    return closest
end
