var compare = function(sCnt, pCnt) {
    for (var i = 0; i < pCnt.length; i++) {
        if (sCnt[i] !== pCnt[i]) return false;
    }
    return true;
};

/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    var sLen = s.length;
    var pLen = p.length;
    var res = [];
    if (sLen < pLen) return res;
    var pCnt = new Array(26);
    var sCnt = new Array(26);
    for (var i = 0; i < 26; i++) {
        pCnt[i] = 0;
        sCnt[i] = 0;
    }
    for (i = 0; i < pLen; i++) {
        pCnt[p[i].charCodeAt() - 'a'.charCodeAt()]++;
    }
    for (i = 0; i < pLen; i++) {
        sCnt[s[i].charCodeAt() - 'a'.charCodeAt()]++;
    }
    if (true === compare(sCnt, pCnt)) {
        res.push(0);
    }
    for (i = pLen; i < sLen; i++) {
        sCnt[s[i - pLen].charCodeAt() - 'a'.charCodeAt()]--;
        sCnt[s[i].charCodeAt() - 'a'.charCodeAt()]++;
        if (true === compare(sCnt, pCnt)) {
            res.push(i - pLen + 1);
        }
    }
    return res;
};