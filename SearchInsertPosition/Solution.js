/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var size = nums.length;
    var l = 0;
    var r = size;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
};
