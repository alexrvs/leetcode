/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    var l = 0;
    var r = nums.length;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (nums[m] >= nums[0]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l >= nums.length) return nums[0];
    return nums[l];
};
