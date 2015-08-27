# @param {Integer} num
# @return {Integer}
def add_digits(num)
    return 1 + (num - 1) % 9 if num != 0 else return 0
end
