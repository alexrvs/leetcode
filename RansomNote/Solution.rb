# @param {String} ransom_note
# @param {String} magazine
# @return {Boolean}
def can_construct(ransom_note, magazine)
    nums = Array.new(26, 0)
    magazine.chars.each do | c |
        nums[c.ord - 'a'.ord] += 1
    end
    ransom_note.chars.each do | c |
        idx = c.ord - 'a'.ord
        nums[idx] -= 1
        return false if nums[idx] < 0
    end
    return true
end
