# @param {Integer} n
# @return {String[]}
def fizz_buzz(n)
    res = []
    1.upto(n) do | i |
        if i % 3 == 0 && i % 5 == 0 then
            res << "FizzBuzz"
        elsif i % 3 == 0 then
            res << "Fizz"
        elsif i % 5 == 0 then
            res << "Buzz"
        else
            res << i.to_s
        end
    end
    return res
end