/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    var aSize = a.length;
    var bSize = b.length;
    var size = aSize > bSize ? aSize : bSize;
    var c = 0;
    var d = [];
    for (var i = 0; i < size; i++) {
        var ad = 0;
        var bd = 0;
        if (aSize - 1 - i >= 0) ad = Number(a[aSize - 1 - i]);
        if (bSize - 1 - i >= 0) bd = Number(b[bSize - 1 - i]);
        d.push(ad + bd + c);
        c = Math.floor(d[i] / 2);
        d[i] %= 2;
    }
    var s = "";
    if (c == 1) s += "1";
    for (i = 0; i < size; i++) {
        s += String(d[size - 1 - i]);
    }
    return s;
};
