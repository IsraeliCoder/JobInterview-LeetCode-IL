
// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02

class Solution {
public:

    vector<int> sortedSquares(vector<int>& nums) {
        
        /*
        
        Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

        

        Example 1:

        Input: nums = [-4,-1,0,3,10]
        Output: [0,1,9,16,100]
        Explanation: After squaring, the array becomes [16,1,0,9,100].
        After sorting, it becomes [0,1,9,16,100].
        Example 2:

        Input: nums = [-7,-3,2,3,11]
        Output: [4,9,9,49,121]

        */

        int n = nums.size();
        vector<int> toReturn(n);

        int p1 = 0;
        int p2 = n - 1;

        int fillinfIndex = n - 1;

        while(p1 <= p2)
        {

            int num1 = nums[p1];
            int num2 = nums[p2];

            if(num1 * num1 < num2 * num2)
            {
                p2--;
                toReturn[fillinfIndex--] = num2 * num2;
            }
            else
            {
                p1++;
                toReturn[fillinfIndex--] = num1 * num1;
            }

        }

        return toReturn;
    }
};