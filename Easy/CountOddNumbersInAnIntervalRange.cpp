
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=daily-question&envId=2025-12-07

/**

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
 

Constraints:

0 <= low <= high <= 10^9

*/

class Solution {
public:
    int countOdds(int low, int high) {
        
        int lowIsEven = low % 2 == 0;
        int highIsEven = high % 2 == 0;

        if(low == high)
            return !lowIsEven;

        int range = (high - low  - 1);
        int result = range / 2;

        // low=4 high=7 1

        if(lowIsEven && highIsEven && range % 2 == 1)
            result++;
        
        return result + (lowIsEven ? 0 : 1) + (highIsEven ? 0 : 1);

    }
};