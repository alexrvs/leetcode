var calStep = function(limit, start, end) {
    let step = 0;
    while (start <= limit) {
        if (limit + 1 < end) {
            step += limit + 1 - start;
        } else {
            step += end - start;
        }
        start *= 10;
        end *= 10;
    }
    return step;
};

/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(n, k) {
    let cur = 1;
    k--;
    while (k > 0) {
        let step = calStep(n, cur, cur + 1);
        if (step <= k) {
            k -= step;
            cur++;
        } else {
            k -= 1;
            cur *= 10;
        }
    }
    return cur;
};