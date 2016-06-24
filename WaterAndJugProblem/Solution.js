var myGCD = function(x, y) {
    return (y === 0 ? x : myGCD(y, x % y));
};

/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x === 0 && y == z) return true;
    if (x == z && y === 0) return true;
    if (x == z || y == z) return true;
    if (z > x + y) return false;
    return (z % myGCD(x, y) === 0);
};
