/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    var nums = new Array(n + 1);
    nums[0] = 1;
    for (var i = 1; i <= n; i++) {
        nums[i] = 0;
        for (var j = 1; j <= i; j++) {
            nums[i] += nums[j - 1] * nums[i - j];
        }
    }
    return nums[n];
};
