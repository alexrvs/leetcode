/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    if (num <= 1) return true;
    let l = 1;
    let r = Math.floor(num / 2);
    let m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        console.log(m);
        if (m < Math.floor(num / m)) l = m + 1;
        else r = m;
    }
    return (l == num / l);
};
