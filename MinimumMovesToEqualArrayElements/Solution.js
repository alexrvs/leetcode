/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    let size = nums.length;
    let res = 0;
    if (size < 2) return res;
    let m = nums[0];
    for (let i = 1; i < size; i++) {
        if (m > nums[i]) m = nums[i];
    }
    for (let i = 0; i < size; i++) {
        res += nums[i] - m;
    }
    return res;
};