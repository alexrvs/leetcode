/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    var size = nums.length;
    if (size < 2) return 0;
    for (var i = 0; i < size; i++) {
        if (i === 0 && nums[i] > nums[i + 1]) return i;
        if (i == size - 1 && nums[i - 1] < nums[i]) return i;
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) return i;
    }
    return 0;
};
