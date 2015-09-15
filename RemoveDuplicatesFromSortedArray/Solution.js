/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var size = nums.length;
    if (size <= 1) return size;
    var lastValue = nums[0];
    var newSize = 1;
    for (var i = 1; i < nums.length; i++) {
        if (nums[i] != lastValue) {
            lastValue = nums[i];
            nums[newSize++] = nums[i];
        }
    }
    return newSize;
};
