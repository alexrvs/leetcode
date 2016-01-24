/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if (n <= 2) return 0;
    if (n <= 4) return n - 2;
    var l = 2;
    while (l * l < n) {
        l++;
    }
    var cnt = 0;
    var nums = new Array(n);
    for (var i = 2; i <= l; i++) {
        if (nums[i] != 1) {
            for (var j = 2 * i; j < n; j += i) {
                nums[j] = 1;
            }
        }
    }
    for (i = 2; i < n; i++) {
        if (nums[i] != 1) {
            cnt++;
        }
    }
    return cnt;
};
