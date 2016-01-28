/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var size = nums.length;
    if (size === 0) {
        return 0;
    }
    var sum = nums[0];
    var max = sum;
    for (var i = 1; i < size; i++) {
        sum += nums[i];
        if (sum < nums[i]) {
            sum = nums[i];
        }
        if (max < sum) {
            max = sum;
        }
    }
    return max;
};
