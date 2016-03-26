var helper = function(candidates, path, index, sum, res) {
    if (sum < 0) return;
    if (sum === 0) {
        res.push(path.slice());
        return;
    }
    var prev = 0;
    for (var i = index; i < candidates.length; i++) {
        if (i > 0 && candidates[i] == prev) {
            continue;
        }
        path.push(candidates[i]);
        helper(candidates, path, i + 1, sum - candidates[i], res);
        path.pop();
        prev = candidates[i];
    }
};

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    var res = [];
    var path = [];
    candidates.sort(function(a, b) {return a - b;});
    helper(candidates, path, 0, target, res);
    return res;
};
