/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    if ((num ^ 0x1) === 0) return true;
    if ((num ^ 0x4) === 0) return true;
    if ((num ^ 0x10) === 0) return true;
    if ((num ^ 0x40) === 0) return true;
    if ((num ^ 0x100) === 0) return true;
    if ((num ^ 0x400) === 0) return true;
    if ((num ^ 0x1000) === 0) return true;
    if ((num ^ 0x4000) === 0) return true;
    if ((num ^ 0x10000) === 0) return true;
    if ((num ^ 0x40000) === 0) return true;
    if ((num ^ 0x100000) === 0) return true;
    if ((num ^ 0x400000) === 0) return true;
    if ((num ^ 0x1000000) === 0) return true;
    if ((num ^ 0x4000000) === 0) return true;
    if ((num ^ 0x10000000) === 0) return true;
    if ((num ^ 0x40000000) === 0) return true;
    return false;
};
