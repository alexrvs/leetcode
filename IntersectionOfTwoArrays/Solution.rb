# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Integer[]}
def intersection(nums1, nums2)
    res = []
    nums1.sort!
    nums2.sort!
    i = 0
    j = 0
    while i < nums1.length && j < nums2.length do
        if nums1[i] == nums2[j] then
            res.push(nums1[i])
            i += 1
            while i < nums1.length && nums1[i] == nums1[i - 1] do
                i += 1
            end
            j += 1
            while j < nums2.length && nums2[j] == nums2[j - 1] do
                j += 1
            end
        elsif nums1[i] < nums2[j] then
            i += 1
            while i < nums1.length && nums1[i] == nums1[i - 1] do
                i += 1
            end
        else
            j += 1
            while j < nums2.length && nums2[j] == nums2[j - 1] do
                j += 1
            end
        end
    end
    return res
end
