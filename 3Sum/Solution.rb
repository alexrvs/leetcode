# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
    res = []
    l = nums.length
    nums.sort!
    i = 0
    while i < l - 2 do
        j = i + 1
        k = l - 1
        while j < k do
            sum = nums[i] + nums[j] + nums[k]
            if sum == 0 then
                r = []
                r << nums[i] << nums[j] << nums[k]
                res << r
                prev = nums[j]
                while j < k && nums[j] == prev do j += 1 end
            elsif sum < 0 then
                prev = nums[j]
                while j < k && nums[j] == prev do j += 1 end
            else
                prev = nums[k]
                while j < k && nums[k] == prev do k -= 1 end
            end
        end
        prev = nums[i]
        while i < l && nums[i] == prev do i += 1 end
    end
    return res
end
