# @param {String} s
# @return {Boolean}
def is_valid(s)
    left = []
    s.chars.each do |c|
        if "([{".include? c
            left << c
        elsif c == ')'
            if left.length > 0 && left[-1] == '('
                left.pop
            else return false end
        elsif c == ']'
            if left.length > 0 && left[-1] == '['
                left.pop
            else return false end
        elsif c == '}'
            if left.length > 0 && left[-1] == '{'
                left.pop
            else return false end
        end
    end
    return false if left.length > 0
    return true
end
