/**
 * @constructor
 */
var Queue = function() {
    this.a_stack = [];
    this.b_stack = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
Queue.prototype.push = function(x) {
    this.a_stack.push(x);
};

/**
 * @returns {void}
 */
Queue.prototype.pop = function() {
    if (this.empty()) return null;
    if (this.b_stack.length === 0) {
        while (this.a_stack.length !== 0) {
            this.b_stack.push(this.a_stack.pop());
        }
    }
    return this.b_stack.pop();
};

/**
 * @returns {number}
 */
Queue.prototype.peek = function() {
    if (this.empty()) return null;
    if (this.b_stack.length !== 0) {
        return this.b_stack[this.b_stack.length - 1];
    }
    return this.a_stack[0];
};

/**
 * @returns {boolean}
 */
Queue.prototype.empty = function() {
    return (this.a_stack.length === 0) && (this.b_stack.length === 0);
};
