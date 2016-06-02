/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    var res = nums[0];
    var tmax = nums[0];
    var tmin = nums[0];
    for (var i = 1; i < nums.length; i++) {
        var prod1 = tmax * nums[i];
        var prod2 = tmin * nums[i];
        tmax = Math.max(Math.max(prod1, prod2), nums[i]);
        tmin = Math.min(Math.min(prod1, prod2), nums[i]);
        res = Math.max(tmax, res);
    }
    return res;
};
