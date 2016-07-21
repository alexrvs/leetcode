/**
 * @param {number[]} nums
 * @return {number}
 */
var wiggleMaxLength = function(nums) {
    var size = nums.length;
    if (size <= 1) return size;
    var len = 1;
    var prev = 0;
    for (var i = 1; i < size; i++) {
        if (prev <= 0 && nums[i] > nums[i - 1]) {
            prev = 1;
            len++;
        } else if (prev >= 0 && nums[i] < nums[i - 1]) {
            prev = -1;
            len++;
        }
    }
    return len;
};
