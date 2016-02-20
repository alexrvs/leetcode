/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    var size = nums.length;
    var l = 0;
    var r = size;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (nums[m] >= nums[0]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    r = l - 1;
    l %= size;
    while (l != r) {
        m = (l + Math.floor(((r - l + size) % size) / 2)) % size;
        if (nums[m] < target) {
            l = (m + 1) % size;
        } else {
            r = m;
        }
    }
    if (nums[l] == target) return l;
    return -1;
};
