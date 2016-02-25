/**
 * @param {number} n
 * @param {number[]} primes
 * @return {number}
 */
var nthSuperUglyNumber = function(n, primes) {
    var k = primes.length;
    var idx = new Array(k);
    var un = new Array(n + 1);
    var i = 0;
    var j = 0;
    var num = 0;
    for (i = 0; i < k; i++) idx[i] = 0;
    for (i = 0; i < n; i++) un[i] = 1;
    un[0] = 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < k; j++) {
            num = primes[j] * un[idx[j]];
            if (un[i] == 1 || num < un[i]) un[i] = num;
        }
        for (j = 0; j < k; j++) {
            num = primes[j] * un[idx[j]];
            if (un[i] == num) idx[j]++;
        }
    }
    return un[n - 1];
};
