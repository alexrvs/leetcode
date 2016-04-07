var dfs = function(nums, idx, used, order, res) {
    var size = nums.length;
    if (idx == size) {
        var r = [];
        console.log("Here");
        for (var i = 0; i < size; i++) {
            r.push(nums[order[i]]);
        }
        res.push(r);
        return;
    }
    for (i = 0; i < size; i++) {
        if (used[i] === 0) {
            used[i] = 1;
            order[idx] = i;
            dfs(nums, idx + 1, used, order, res);
            used[i] = 0;
            while (i + 1 < size && nums[i] == nums[i + 1]) i++;
        }
    }
};

var createArray = function(size, val) {
    var arr = [];
    for (var i = 0; i < size; i++) {
        arr[i] = val;
    }
    return arr;
};

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    var size = nums.length;
    var order = createArray(size, 0);
    var used = createArray(size, 0);
    var res = [];
    nums.sort(function(a, b) { return a - b; });
    dfs(nums, 0, used, order, res);
    return res;
};
