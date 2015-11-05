/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    var l = secret.length;
    var s = [];
    var g = [];
    for (var i = 0; i < 10; i++) {
        s.push(0);
        g.push(0);
    }
    var b = 0;
    var c = 0;
    for (i = 0; i < l; i++) {
        if (secret[i] == guess[i]) b++;
        s[secret[i] - '0']++;
        g[guess[i] - '0']++;
    }
    for (i = 0; i < 10; i++) {
        c += (s[i] < g[i] ? s[i] : g[i]);
    }
    c -= b;
    return b + "A" +  c + "B";
};
