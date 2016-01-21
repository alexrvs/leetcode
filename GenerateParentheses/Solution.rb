def helper(res, str, a, b)
    if a == 0 && b == 0 then
        res << str
    elsif a == 0 then
        helper(res, str + ")", a, b - 1)
    else
        helper(res, str + "(", a - 1, b)
        if a < b then
            helper(res, str + ")", a, b - 1)
        end
    end
end

# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
    res = []
    str = ""
    helper(res, str, n, n)
    return res
end
