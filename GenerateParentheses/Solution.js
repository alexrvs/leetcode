var helper = function(res, str, a, b) {
    if (a === 0 && b === 0) {
        res.push(str);
    } else if (a === 0) {
        helper(res, str + ")", a, b - 1);
    } else {
        helper(res, str + "(", a - 1, b);
        if (a < b) {
            helper(res, str + ")", a, b - 1);
        }
    }
    return;
}

/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var res = [];
    var str = "";
    helper(res, str, n, n);
    return res;
};
