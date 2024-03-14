
// https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-14

class Solution {
public:
    int pivotInteger(int n) {
        
        /*
        
        Given a positive integer n, find the pivot integer x such that:

        The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
        Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

        

        Example 1:

        Input: n = 8
        Output: 6
        Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
        Example 2:

        Input: n = 1
        Output: 1
        Explanation: 1 is the pivot integer since: 1 = 1.
        Example 3:

        Input: n = 4
        Output: -1
        Explanation: It can be proved that no such integer exist.
 
        
        */

        if(n == 1)
            return n;

        int sum = ((n + 1) * n) / 2;

        int runningSum = 0;
        for(int i = 1; i < n; i++)
        {
            if(runningSum == sum - i - runningSum)
                return i;

            runningSum += i;

        }

        return -1;

    }
};