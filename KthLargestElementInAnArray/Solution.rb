def heapify(heap, k)
    i = k - 1
    while i > 0 do
        r = (i - 1) / 2
        if heap[r] > heap[i] then
            tmp = heap[r]
            heap[r] = heap[i]
            heap[i] = tmp
        end
        i -= 1
    end
end

# @param {Integer[]} nums
# # @param {Integer} k
# # @return {Integer}
def find_kth_largest(nums, k)
    heapify(nums, k)
    i = k
    while i < nums.length do
        if nums[i] > nums[0] then
            tmp = nums[i]
            nums[i] = nums[0]
            nums[0] = tmp
            heapify(nums, k)
        end
        i += 1
    end
    return nums[0]
end
