var helper = function(candidates, path, index, sum, res) {
    if (sum < 0) return;
    if (sum === 0) {
        res.push(path.slice());
        return;
    }
    for (var i = index; i < candidates.length; i++) {
        path.push(candidates[i]);
        helper(candidates, path, i, sum - candidates[i], res);
        path.pop();
    }
};

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    var res = [];
    var path = [];
    candidates.sort(function(a, b) {return a - b;});
    helper(candidates, path, 0, target, res);
    return res;
};
