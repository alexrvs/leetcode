/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  var start = 0;
  var length = 0;
  var max = 0;
  var i = 0;
  var s_len = s.length;
  if (s_len == 0) {
    return 0;
  }
  for (i = 1; i < s_len; i++) {
    for (var j = start; j < i; j++) {
      if (s.charAt(j) == s.charAt(i)) {
        length = i - start;
        if (max < length) {
          max = length;
        }
        start = j+1;
        break;
      }
    }
  }
  length = s_len - start;
  if (max < length) {
    max = length;
  }
  return max;
};

var str1 = "abca";
console.log(lengthOfLongestSubstring(str1));
