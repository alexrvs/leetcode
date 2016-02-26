var search = function(seq, l, r, target) {
    while (l < r) {
        var m = l + ((r - l) >> 1);
        if (seq[m] < target) l = m + 1;
        else r = m;
    }
    return l;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    var n = nums.length;
    if (n === 0) return 0;
    var seq = new Array(n);
    var len = 0;
    for (var i = 0; i < n; i++) {
        var pos = search(seq, 0, len, nums[i]);
        seq[pos] = nums[i];
        if (pos == len) len++;
    }
    return len;
};
