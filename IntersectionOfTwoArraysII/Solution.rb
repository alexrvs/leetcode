# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Integer[]}
def intersect(nums1, nums2)
        res = []
    nums1.sort!
    nums2.sort!
    i = 0
    j = 0
    while i < nums1.length && j < nums2.length do
        if nums1[i] == nums2[j] then
            res.push(nums1[i])
            i += 1
            j += 1
        elsif nums1[i] < nums2[j] then
            i += 1
        else
            j += 1
        end
    end
    return res
end
