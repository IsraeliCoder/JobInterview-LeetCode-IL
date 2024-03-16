
// https://leetcode.com/problems/contiguous-array/

class Solution {
public:


    int findMaxLength(vector<int>& nums) {
        
        /*
        
        Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

        Example 1:

        Input: nums = [0,1]
        Output: 2
        Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
        Example 2:

        Input: nums = [0,1,0]
        Output: 2
        Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
        
        */

        int n = nums.size();
        int sum = 0;
        int maxLength = 0;
        unordered_map<int, int> sumToFirstIndex = {{0, 0}};

        for(int i = 0; i < n; i++)
        {

            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if(sumToFirstIndex.count(sum))
                maxLength = max(maxLength, i + 1 - sumToFirstIndex[sum]);
            else
                sumToFirstIndex[sum] = i + 1;

        }

        return maxLength;

    }

};