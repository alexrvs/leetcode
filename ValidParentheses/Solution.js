/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    for (var i = 0; i < s.length; i++) {
        if ('(' == s[i] || '{' == s[i] || '[' == s[i]) {
            stack.push(s[i]);
        } else {
            var tail = stack.length - 1;
            if (tail < 0) return false;
            if (')' == s[i]) {
                if ('(' == stack[tail]) {
                    stack.pop()
                } else {
                    return false;
                }
            } else if ('}' == s[i]) {
                if ('{' == stack[tail]) {
                    stack.pop()
                } else {
                    return false;
                }
            } else if (']' == s[i]) {
                if ('[' == stack[tail]) {
                    stack.pop()
                } else {
                    return false;
                }
            }
        }
    }
    if (stack.length !== 0) return false;
    return true;
};
