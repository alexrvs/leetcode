var helper = function(k, path, index, sum, res) {
    if (k < 0 || sum < 0) return;
    if (k === 0 && sum === 0) {
        res.push(path.slice());
        return;
    }
    for (var i = index; i <= 9; i++) {
        path.push(i);
        helper(k - 1, path, i + 1, sum - i, res);
        path.pop();
    }
};

/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function(k, n) {
    var res = [];
    var path = [];
    helper(k, path, 1, n, res);
    return res;
};
