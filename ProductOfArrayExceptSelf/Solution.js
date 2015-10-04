/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var size = nums.length;
    var res = [1];
    for (var i = 1; i < size; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    var prod = 1;
    for (var i = size - 1; i >= 0; i--) {
        res[i] *= prod;
        prod *= nums[i];
    }
    return res;
};  
