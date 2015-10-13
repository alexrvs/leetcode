# @param {Integer} n
# @return {Boolean}
def can_win_nim(n)
    return false if n % 4 == 0
    return true
end
