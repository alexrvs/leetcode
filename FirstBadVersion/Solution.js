/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        var l = 1;
        var r = n;
        var m = 0;
        while (l < r) {
            m = l + Math.floor((r - l) / 2);
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    };
};
