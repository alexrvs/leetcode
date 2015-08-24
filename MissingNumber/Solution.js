/**
 * @param {number[]} nums
 * @return {number}
 */

var missingNumber = function(nums) {
    x = nums[0];
    x ^= 0;
    for (var i = 1; i < nums.length; i++) {
        x ^= nums[i];
        x ^= i;
    }
    x ^= nums.length;
    return x;
};

