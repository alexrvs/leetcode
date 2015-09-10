/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    var nums = [0];
    for (var i = 1; i <= n; i++) {
        var least = i;
        for (var x = 1; x * x <= i; x++) {
            var num = 1 + nums[i - x * x];
            if (least > num) {
                least = num;
            }
        }
        nums.push(least);
    }
    return nums[n];
};
