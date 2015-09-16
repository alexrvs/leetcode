# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
    return n if n <= 2
    ways = []
    ways << 0
    ways << 1
    ways << 2
    i = 3
    while i <= n do ways << ways[i - 1] +  ways[i - 2]; i += 1 end
    return ways[n]
end
