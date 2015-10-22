/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var size = nums.length;
    var cnts = [0, 0, 0];
    for (var i = 0; i < size; i++) {
        cnts[nums[i]]++;
    }
    var idx = 0;
    for (i = 0; i < 3; i++) {
        for (var j = 0; j < cnts[i]; j++) {
            nums[idx++] = i;
        }
    }
    return;
};
