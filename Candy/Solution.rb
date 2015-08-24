# @param {Integer[]} ratings
# @return {Integer}
def candy(ratings)
  candies = [1]
  ratings.each_with_index do | r, i |
    if i > 0
      if ratings[i] > ratings[i-1]
        candies << candies[i-1] + 1
      else
        candies << 1
      end
    end
  end
  total = candies.last
  ratings.to_enum.with_index.reverse_each do | r, i |
    if i < ratings.length - 1
      if ratings[i] > ratings[i + 1]
        num = candies[i + 1] + 1
        if num > candies[i]
          candies[i] = num
        end
      end
    total += candies[i]
    end
  end
  return total
end
