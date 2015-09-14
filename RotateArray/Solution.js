/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var reverse = function(nums, i, j) {
    var tmp = 0;
    for (;i < j; i++, j--) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    return;
};

var rotate = function(nums, k) {
    var size = nums.length;
    k = k%size;
    if (k > 0) {
        reverse(nums, 0, size - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);
    }
    return;
};
