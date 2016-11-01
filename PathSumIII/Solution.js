/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
var helper = function(root, sums, target) {
    let cnt = 0;
    if (root === null) return cnt;
    for (let i = 0; i < sums.length; i++) {
        sums[i] += root.val;
        if (sums[i] == target) cnt++;
    }
    if (root.val == target) cnt++;
    sums.push(root.val);
    cnt += helper(root.left, sums, target);
    cnt += helper(root.right, sums, target);
    sums.pop();
    for (let i = 0; i < sums.length; i++) {
        sums[i] -= root.val;
    }
    return cnt;
};
 
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
var pathSum = function(root, sum) {
    let sums = [];
    return helper(root, sums, sum);
};