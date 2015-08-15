class MinStack
    # Initialize your data structure here
    def initialize
      @elements = []
      @minIndexes = []
    end

    # @param {Integer} x
    # @return {Void} nothing
    def push(x)
      @elements << x
      if @minIndexes.size == 0 || x < @elements[@minIndexes.last]
        @minIndexes << @elements.size - 1
      end
    end

    # @return {Void} nothing
    def pop
      if @minIndexes.last == @elements.size - 1
        @minIndexes.pop
      end
      @elements.pop
    end

    # @return {Integer}
    def top
      return @elements.last
    end

    # @return {Integer}
    def get_min
      return @elements[@minIndexes.last]
    end
end
