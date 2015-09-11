/**
 * @param {string} input
 * @return {number[]}
 */
var diffWaysToCompute = function(input) {
    var res = [];
    if (/^\d+$/.test(input)) {
        res.push(Number(input));
        return res;
    }
    for (var i = 0; i < input.length; i++) {
        var op = input[i]
        if (/^[*+-]$/.test(op)) {
            var left = diffWaysToCompute(input.substr(0, i))
            var right = diffWaysToCompute(input.substr(i+1))
            for (var j = 0; j < left.length; j++) {
                for (var k = 0; k < right.length; k++) {
                    switch(op) {
                        case '+':
                            res.push(left[j]+right[k]);
                            break;
                        case '-':
                            res.push(left[j]-right[k]);
                            break;
                        case '*':
                            res.push(left[j]*right[k]);
                            break;
                    }
                }
            }
        }
    }
    return res;
};
