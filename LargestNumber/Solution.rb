class SortInt
    include Comparable
    attr :num
    def <=>(other)
        s1 = num.to_s + other.num.to_s
        s2 = other.num.to_s + num.to_s
        s1 <=> s2
    end
    def initialize(num)
        @num = num
    end
    def inspect
        @str
    end
end

# @param {Integer[]} nums
# @return {String}
def largest_number(nums)
    sorted = []
    nums.each do | n |
        sorted << SortInt.new(n)
    end
    sorted.sort!
    sorted.reverse!
    res = ""
    isZero = true
    sorted.each do | s |
        isZero = false if s.num != 0
        res += s.num.to_s
    end
    return "0" if isZero == true
    return res
end
