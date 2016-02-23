/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    var n = nums.length;
    if (n < 3) return false;
    var a = [0, 0];
    a[0] = nums[0];
    var i = 0;
    for (i = 1; i < n; i++) {
        if (a[0] < nums[i]) a[0] = nums[i];
    }
    a[1] = a[0];
    for (i = 0; i < n; i++) {
        if (nums[i] <= a[0]) {
            a[0] = nums[i];
        } else if (nums[i] < a[1]) {
            a[1] = nums[i];
        }
        if (nums[i] > a[0] && nums[i] > a[1]) return true;
    }
    return false;
};
