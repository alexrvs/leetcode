/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
  candies = [1];
  for ( var i = 1; i < ratings.length; i++ ) {
    if ( ratings[i] > ratings[i-1] ) {
      candies[i] = candies[i-1] + 1;
    } else {
      candies[i] = 1;
    }
  }
  var sum = candies[candies.length-1];
  for ( i = candies.length-2; i >= 0; i-- ) {
    if ( ratings[i] > ratings[i+1] ) {
      var num = candies[i+1] + 1;
      if ( num > candies[i] ) {
        candies[i] = num;
      }
    }
    sum += candies[i];
  }
  return sum;
};
