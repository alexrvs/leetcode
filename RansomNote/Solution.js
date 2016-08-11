/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    var nums = new Array(26);
    var i = 0;
    var idx = 0;
    for (i = 0; i < 26; i++) {
        nums[i] = 0;
    }
    for (i = 0; i < magazine.length; i++) {
        idx = magazine[i].charCodeAt() - 'a'.charCodeAt();
        nums[idx]++;
    }
    for (i = 0; i < ransomNote.length; i++) {
        idx = ransomNote[i].charCodeAt() - 'a'.charCodeAt();
        nums[idx]--;
        if (nums[idx] < 0) return false;
    }
    return true;
};
