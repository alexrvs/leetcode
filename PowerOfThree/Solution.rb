# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
    return false if n < 1
    while n != 1 do
        if n % 3 == 0 then
            n /= 3
        else
            return false
        end
    end
    return true   
end
