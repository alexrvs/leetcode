/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x < 2) return x;
    var l = 1;
    var r = x;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (m < x / m) {
            l = m + 1;
        } else if (m == x / m){
            return m;
        } else {
            r = m;
        }
    }
    return l - 1;
};
