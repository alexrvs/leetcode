var addSpaces = function(str, i, n, l, leftJust) {
    if (n > 0 && i < n) {
        var spaces = leftJust ? 1 : (Math.floor(l / n) + (i < l % n ? 1 : 0));
        while (spaces > 0) {
            str += " ";
            spaces--;
        }
    }
    return str;
}

var connect = function(words, from, to, len, maxWidth, leftJust) {
    var str = "";
    for (var i = from; i <= to; i++) {
        str += addSpaces(words[i], i - from, to - from, maxWidth - len, leftJust);
    }
    while (str.length < maxWidth) str += " ";
    return str;
};

/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    var res = [];
    var i = 0;
    var from = 0;
    var l = 0
    for (i = 0; i < words.length; i++) {
        if (l + words[i].length + (i - from) > maxWidth) {
            res.push(connect(words, from, i - 1, l, maxWidth, false));
            from = i;
            l = 0;
        }
        l += words[i].length;
    }
    res.push(connect(words, from, i - 1, l, maxWidth, true));
    return res;
};
