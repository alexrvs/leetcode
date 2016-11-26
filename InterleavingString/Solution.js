/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function(s1, s2, s3) {
    let size1 = s1.length;
    let size2 = s2.length;
    let size3 = s3.length;
    if (size1 + size2 != size3) return false;
    let dp = [];
    for (let i = 0; i <= size1; i++) {
        dp[i] = [];
        for (let j = 0; j <= size2; j++) {
            if (i === 0 && j === 0) {
                dp[i][j] = true;
            } else if (i === 0) {
                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            } else if (j === 0) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            } else {
                dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
            }
        }
    }
    return dp[size1][size2];
};