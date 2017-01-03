/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    let r = matrix.length;
    if (r === 0) return 0;
    let c = matrix[0].length;
    if (c === 0) return 0;
    let dp = [];
    for (let i = 0; i <= r; i++) {
        dp.push([]);
        for (let j = 0; j <= c; j++) {
            dp[i].push(0);
        }
    }
    let maxL = 0;
    for (let i = 1; i <= r; i++) {
        for (let j = 1; j <= c; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = dp[i - 1][j - 1];
                if (dp[i - 1][j] < dp[i][j]) dp[i][j] = dp[i - 1][j];
                if (dp[i][j - 1] < dp[i][j]) dp[i][j] = dp[i][j - 1];
                dp[i][j]++;
                if (maxL < dp[i][j]) maxL = dp[i][j];
            }
        }
    }
    return maxL * maxL;
};