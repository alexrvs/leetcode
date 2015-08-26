/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    uglyNums = [1];
    i2 = i3 = i5 = 0;
    while (uglyNums.length < n) {
        num2 = uglyNums[i2]*2;
        num3 = uglyNums[i3]*3;
        num5 = uglyNums[i5]*5;
        minNum = Math.min(num2, num3, num5);
        uglyNums.push(minNum);
        if (minNum == num2) i2++;
        if (minNum == num3) i3++;
        if (minNum == num5) i5++;
    }
    return uglyNums[uglyNums.length - 1];
};
