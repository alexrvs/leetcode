/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    var res = [];
    if (n === 0) {
        res.push(0);
        return res;
    }
    var num = 1;
    var i = 0;
    for (i = 1; i < n; i++) {
        num <<= 1;
        num |= 0x01;
    }
    var mask = 1;
    var idx = 0;
    for (i = 0; i <= num; i++) {
        if (i < 2) res.push(i);
        else {
            if (i == mask << 1) {
                mask <<= 1;
                idx = i - 1;
            }
            res.push( mask ^ res[idx--]);
        }
    }
    return res;
};
