class Solution {
    func countBits(num: Int) -> [Int] {
        var res = [Int](count: num + 1, repeatedValue: 0);
        res[0] = 0;
        var n = 1;
        for var i = 1; i <= num; i++ {
            if i - n >= n {
                n <<= 1;
            }
            res[i] = 1 + res[i - n];
        }
        return res;
    }
}
