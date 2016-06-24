def myGCD(x, y)
    return x if y == 0
    return myGCD(y, x % y)
end

# @param {Integer} x
# @param {Integer} y
# @param {Integer} z
# @return {Boolean}
def can_measure_water(x, y, z)
    return true if x == 0 && y == z
    return true if x == z && y == 0
    return true if x == z || y == z
    return false if z > x + y
    return z % myGCD(x, y) == 0
end
