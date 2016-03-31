class Queue
    # Initialize your data structure here.
    def initialize
        @a = []
        @b = []
    end

    # @param {Integer} x
    # @return {void}
    def push(x)
        @a << x
    end

    # @return {void}
    def pop
        peek
        @b.pop
    end

    # @return {Integer}
    def peek
        if @b.empty? then
            while ! @a.empty? do
                @b << @a.pop
            end
        end
        return @b.last
    end

    # @return {Boolean}
    def empty
        return (@a.empty? && @b.empty?)
    end
end
