/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    let cur = 1;
    let res = [];
    for (let i = 1; i <= n; i++) {
        res.push(cur);
        if (cur * 10 <= n) cur *= 10;
        else if (cur + 1 <= n && cur % 10 != 9) cur++;
        else {
            while ((Math.floor(cur / 10)) % 10 == 9) cur = Math.floor(cur / 10);
            cur = Math.floor(cur / 10) + 1;
        }
    }
    return res;
};