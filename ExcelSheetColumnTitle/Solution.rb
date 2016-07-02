# @param {Integer} n
# @return {String}
def convert_to_title(n)
    res = ""
    while n > 0 do
        n -= 1
        res = ('A'.ord + n % 26).chr + res
        n /= 26
    end
    return res
end
