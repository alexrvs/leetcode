/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var res = [-1, -1];
    var n = nums.length;
    var l = 0;
    var r = n;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l == n || nums[l] !== target) {
        return res;
    }
    res[0] = l;
    l = 0;
    r = n;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    res[1] = l - 1;
    return res;
};
