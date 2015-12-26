/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var l = height.length;
    var i = 0;
    var j = l - 1;
    var area = 0;
    var max = 0;
    while (i < j) {
        var h = height[i];
        if (height[i] >= height[j]) {
            h = height[j];
        }
        area = h * (j - i);
        if (area > max) {
            max = area;
        }
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max;
};
