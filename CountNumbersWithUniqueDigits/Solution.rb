# @param {Integer} n
# @return {Integer}
def count_numbers_with_unique_digits(n)
    sum = 0
    temp = 9
    i = 0
    while i <= n and i <= 10 do
        if i == 0 then
            sum += 1
        elsif i == 1 then
            sum += 9
        else
            temp *= [0, 11 - i].max
            sum += temp
        end
        i += 1
    end
    return sum
end
