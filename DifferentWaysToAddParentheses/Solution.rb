# @param {String} input
# @return {Integer[]}
def diff_ways_to_compute(input)
    puts input
    return [input.to_i] if input =~ /\A[0-9]+\z/
    res = []
    input.chars.each_with_index do |c, i|
        if "+-*".include? c then
            left = diff_ways_to_compute(input.slice(0..i-1))
            right = diff_ways_to_compute(input.slice(i+1..-1))
            left.each do |j|
                right.each do |k|
                    if c == '+' then
                        res << j+k
                    elsif c == '-' then
                        res << j-k
                    elsif c == '*' then
                        res << j*k
                    end
                end
            end
        end
    end
    return res
end
