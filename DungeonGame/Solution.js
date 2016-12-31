/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
    let needHP = [];
    let r = dungeon.length;
    if (r === 0) return 0;
    let c = dungeon[0].length;
    if (c === 0) return 0;
    for (let i = 0; i < r; i++) {
        needHP.push([]);
        for (let j = 0; j < c; j++) {
            needHP[i].push(0);
        }
    }
    for (let i = r - 1; i >= 0; i--) {
        for (let j = c - 1; j >= 0; j--) {
            if (i === r - 1 && j === c - 1) {
                needHP[i][j] = Math.max(1, 1 - dungeon[i][j]);
            } else if (i === r - 1) {
                needHP[i][j] = Math.max(1, needHP[i][j + 1] - dungeon[i][j]);
            } else if (j === c - 1) {
                needHP[i][j] = Math.max(1, needHP[i + 1][j] - dungeon[i][j]);
            } else {
                if (needHP[i][j + 1] < needHP[i + 1][j]) {
                    needHP[i][j] = Math.max(1, needHP[i][j + 1] - dungeon[i][j]);
                } else {
                    needHP[i][j] = Math.max(1, needHP[i + 1][j] - dungeon[i][j]);
                }
            }
            console.log(needHP[i][j]);
        }
    }
    return needHP[0][0];
};