# @param {Integer[]} nums
# @return {Integer[]}
def majority_element(nums)
    num1 = num2 = cnt1 = cnt2 = 0
    nums.each do | n |
        if cnt1 > 0 && n == num1
            cnt1 += 1
            next
        end
        if cnt2 > 0 && n == num2
            cnt2 += 1
            next
        end
        if cnt1 == 0
            num1 = n
            cnt1 += 1
            next
        end
        if cnt2 == 0
            num2 = n
            cnt2 += 1
            next
        end
        cnt1 -= 1
        cnt2 -= 1
    end
    num1 = nil if cnt1 == 0
    num2 = nil if cnt2 == 0
    cnt1 = cnt2 = 0
    nums.each do |n|
        cnt1 += 1 if n == num1
        cnt2 += 1 if n == num2
    end
    res = []
    res << num1 if cnt1 > nums.length / 3
    res << num2 if cnt2 > nums.length / 3
    return res
end
