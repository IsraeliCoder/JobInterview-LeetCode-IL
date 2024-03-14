
// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:

    int sumOfNumber(int k)
    {
        return k * (k + 1) / 2;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        /*
        
        Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

        A subarray is a contiguous part of the array.

        

        Example 1:

        Input: nums = [1,0,1,0,1], goal = 2
        Output: 4
        Explanation: The 4 subarrays are bolded and underlined below:
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
        Example 2:

        Input: nums = [0,0,0,0,0], goal = 0
        Output: 15
                
        */

        int toReturn  = 0;
        int numsSize = nums.size();

        vector<int> indexes;
        for(int i = 0 ; i < numsSize; i++)
        {
            if(nums[i])
                indexes.push_back(i);
        }

        int indexesSize = indexes.size();

        if(goal == 0)
        {
            if(!indexesSize)
                return sumOfNumber(numsSize);

            if(indexes[0] != 0)
            {
                toReturn += sumOfNumber(indexes[0]);
            }

            for(int i = 0; i < indexesSize - 1; i++)
            {
                toReturn += sumOfNumber(indexes[i + 1] - indexes[i] - 1);
            }

            toReturn += sumOfNumber(numsSize - 1 - indexes[indexesSize - 1]);

            return toReturn;

        }

        for(int i = 0; i < indexesSize - goal + 1; i++)
        {

            int startIndex = i == 0 ? 0 : indexes[i - 1] + 1;
            int endIndex = i + goal < indexesSize? indexes[i + goal] - 1 : numsSize - 1;

            int firstIndex = indexes[i];
            int lastIndex = indexes[i + goal - 1];

            toReturn += (firstIndex - startIndex + 1) * (endIndex - lastIndex + 1);

        }

        return toReturn;

    }
};