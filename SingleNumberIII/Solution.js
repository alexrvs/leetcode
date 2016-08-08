/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    var x = 0;
    for (var i = 0; i < nums.length; i++) {
        x ^= nums[i];
    }
    x &= -x;
    var res = [0, 0];
    for (i = 0; i < nums.length; i++) {
        if ((x & nums[i]) === 0) {
            res[0] ^= nums[i];
        } else {
            res[1] ^= nums[i];
        }
    }
    return res;
};
