/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var major = nums[0];
    var c = 1;
    for (var i = 1; i < nums.length; i++) {
        if (c !== 0) {
            if (major != nums[i]) {
                c--;
            } else {
                c++;
            }
        } else {
            major = nums[i];
            c = 1;
        }
    }
    return major;
};
