/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function(timeSeries, duration) {
    let size = timeSeries.length;
    if (0 === size) return 0;
    let res = duration;
    for (let i = 1; i < size; i++) {
        let diff = timeSeries[i] - timeSeries[i - 1];
        if (diff < duration) {
            res += diff;
        } else {
            res += duration;
        }
    }
    return res;
};