/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    var l1 = num1.length;
    var l2 = num2.length;
    var n1 = new Array(l1);
    var n2 = new Array(l2);
    var num = new Array(l1 + l2);
    var i = 0;
    var j = 0;
    for (i = 0; i < l1 + l2; i++) {
        num[i] = 0;
    }
    for (i = 0; i < l1; i++) {
        n1[i] = num1[i] - '0';
    }
    for (i = 0; i < l2; i++) {
        n2[i] = num2[i] - '0';
    }
    if (n1[0] === 0 || n2[0] === 0) {
        return "0";
    }
    for (i = 0; i < l1; i++) {
        for (j = 0; j < l2; j++) {
            num[i + j + 1] += n1[i] * n2[j];
        }
    }
    for (i = l1 + l2 - 1; i >= 0; i--) {
        if (i > 0) {
            num[i - 1] += Math.floor(num[i] / 10);
        }
        num[i] %= 10;
    }
    var res = "";
    if (num[0] !== 0) {
        res += String(num[0]);
    }
    for (i = 1; i < l1 + l2; i++) {
        res += String(num[i]);
    }
    return res;
};
