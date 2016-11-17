var isSame = function(str, pl, s) {
    for (let i = 0; i < pl; i++) {
        if (str[i] != str[s + i]) return false;
    }
    return true;
}

/**
 * @param {string} str
 * @return {boolean}
 */
var repeatedSubstringPattern = function(str) {
    let size = str.length;
    for (let l = 1; l <= size >> 1; l++) {
        if (size % l === 0) {
            let repeated = true;
            for (let s = l; s < size; s += l) {
                if (false === isSame(str, l, s)) {
                    repeated = false;
                    break;
                }
            }
            if (true === repeated) return true;
        }
    }
    return false;
};