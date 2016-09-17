/**
 * @param {number[]} A
 * @return {number}
 */
var maxRotateFunction = function(A) {
    var sum = 0;
    var total = 0;
    var i = 0;
    var size = A.length;
    for (i = 0; i < size; i++) {
        total += A[i];
        sum += i * A[i];
    }
    var max = sum;
    for (i = 1; i < size; i++) {
        sum += total - size * A[size - i];
        if (max < sum) max = sum;
    }
    return max;
};
