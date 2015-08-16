/**
 * @constructor
 */
var MinStack = function() {
  this.elements = [];
  this.minIndexes = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
MinStack.prototype.push = function(x) {
  this.elements.push(x);
  if (this.minIndexes.length == 0 ||
      x < this.elements[this.minIndexes[this.minIndexes.length - 1]]) {
    this.minIndexes.push(this.elements.length - 1);
  }
};

/**
 * @returns {void}
 */
MinStack.prototype.pop = function() {
  if (this.minIndexes[this.minIndexes.length - 1] === this.elements.length - 1) {
    this.minIndexes.pop();
  }
  this.elements.pop();
};

/**
 * @returns {number}
 */
MinStack.prototype.top = function() {
  return this.elements[this.elements.length - 1];
};

/**
 * @returns {number}
 */
MinStack.prototype.getMin = function() {
  return this.elements[this.minIndexes[this.minIndexes.length - 1]];
};
