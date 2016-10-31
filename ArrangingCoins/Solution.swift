class Solution {
    func arrangeCoins(_ n: Int) -> Int {
        var l: Int = 1
        var remain: Int = n
        while remain >= l {
            remain -= l
            l += 1
        }
        return l - 1
    }
}