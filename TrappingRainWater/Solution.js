/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    var size = height.length;
    var forward = new Array(size);
    var backward = new Array(size);
    var maxH = 0;
    for (var i = 0; i < size; i++) {
        if (maxH < height[i]) maxH = height[i];
        forward[i] = maxH - height[i];
    }
    maxH = 0;
    var sum = 0;
    for (i = size - 1; i >= 0; i--) {
        if (maxH < height[i]) maxH = height[i];
        backward[i] = maxH - height[i];
        sum += (forward[i] < backward[i] ? forward[i] : backward[i]);
    }
    return sum;
};
