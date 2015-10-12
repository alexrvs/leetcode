/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    var psize = pattern.length;
    var words = str.split(' ');
    var wsize = words.length;
    if (psize != wsize) return false;
    var dict = {};
    for (var i = 0; i < psize; i++) {
        var c = pattern[i];
        if (c in dict) {
            if (dict[c] != words[i]) return false;
        } else {
            for (var key in dict){
                if (dict[key] == words[i]) return false;
            }
            dict[c] = words[i];
        }
    }
    return true;
};
