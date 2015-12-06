# @param {String} num1
# @param {String} num2
# @return {String}
def multiply(num1, num2)
    l1 = num1.length
    l2 = num2.length
    n1 = Array.new(l1, 0)
    n2 = Array.new(l2, 0)
    num = Array.new(l1 + l2, 0)
    num1.chars.each_with_index do | c, i |
        n1[i] = c.to_i
    end
    num2.chars.each_with_index do | c, i |
        n2[i] = c.to_i
    end
    return "0" if n1[0] == 0 || n2[0] == 0
    n1.each_with_index do | x, i |
        n2.each_with_index do | y, j |
            num[i + j + 1] += x * y
        end
    end
    i = l1 + l2 - 1
    while i >= 0 do
        if i > 0 then
            num[i - 1] += num[i] / 10
        end
        num[i] %= 10
        i -= 1
    end
    res = ""
    num.each_with_index do | n, i |
        if i == 0 then
            res += n.to_s if n != 0
        else
            res += n.to_s
        end
    end
    return res
end
