
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /*
        
        Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

        The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

        You must write an algorithm that runs in O(n) time and without using the division operation.

        

        Example 1:

        Input: nums = [1,2,3,4]
        Output: [24,12,8,6]
        Example 2:

        Input: nums = [-1,1,0,-3,3]
        Output: [0,0,9,0,0]
        
        */

        int n = nums.size();

        vector<int> mulUp(n);
        vector<int> mulDown(n);
        vector<int> toReturn(n);

        for(int i = 0 ; i < n; i++)
        {

            if(i == 0)
            {
                mulUp[i] = 1;
                mulDown[n - i - 1] = 1;
            }
            else
            {
                mulUp[i] = nums[i - 1] * mulUp[i - 1];
                mulDown[n - i - 1] = nums[n - i] * mulDown[n - i];
            }

        }

        for(int i = 0; i < n; i++)
            toReturn[i] = mulUp[i] * mulDown[i];

        return toReturn;


    }
};