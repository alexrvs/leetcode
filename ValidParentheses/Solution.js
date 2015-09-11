/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var si = -1;
    for (var i = 0; i < s.length; i++) {
        switch(s[i]) {
            case '(':
            case '{':
            case '[':
                stack.push(s[i]);
                si++;
                break;
            case ')':
                if ( si >= 0 && '(' === stack[si]) {
                    stack.pop();
                    si--;
                } else return false;
                break;
            case '}':
                if ( si >= 0 && '{' === stack[si]) {
                    stack.pop();
                    si--;
                } else return false;
                break;
            case ']':
                if ( si >= 0 && '[' === stack[si]) {
                    stack.pop();
                    si--;
                } else return false;
                break;
        }
    }
    if (si >= 0) return false;
    return true;
};
