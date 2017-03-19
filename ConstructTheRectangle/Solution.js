/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
    let res = [];
    for (let i = area; i > 0; i--) {
        if (area % i === 0) {
            let w = i;
            let l = area / i;
            if (w <= l) {
                res.push(l);
                res.push(w);
                break;
            }
        }
    }
    return res;
};