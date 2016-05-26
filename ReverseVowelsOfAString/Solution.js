var isVowel = function(c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }
    return false;
};

/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    var size = s.length;
    var l = 0;
    var r = size - 1;
    var a = s.split("");
    while (l < r) {
        if (isVowel(a[l]) && isVowel(a[r])) {
            var c = a[l];
            a[l] = a[r];
            a[r] = c;
            l++;
            r--;
        } else {
            if (false === isVowel(a[l])) l++;
            if (false === isVowel(a[r])) r--;
        }
    }
    return a.join("");
};
