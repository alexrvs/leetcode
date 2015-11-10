class NumArray

    # Initialize your data structure here.
    # @param {Integer[]} nums
    def initialize(nums)
        @nums = nums
        @sums = []
        @sums << 0
        i = 1
        while i < nums.length do
            @sums << @sums[i - 1] + nums[i - 1]
            i += 1
        end
    end

    # @param {Integer} i
    # @param {Integer} j
    # @return {Integer}
    def sum_range(i, j)
        return @sums[j] - @sums[i] + @nums[j]
    end
end

# Your NumArray object will be instantiated and called as such:
# num_array = NumArray.new(nums)
# num_array.sum_range(0, 1)
# num_array.sum_range(0, 2)
