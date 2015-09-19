/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    var size = nums.length;
    var cur = 0;
    for (var i = 0; i < size; i++) {
        if (nums[i] !== 0) {
            nums[cur++] = nums[i];
        }
    }
    for (; cur < size; cur++) {
        nums[cur] = 0;
    }
    return;
};
