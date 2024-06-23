
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:


    int getMaxIndex(vector<int>& nums, int target, int startIndex, int endIndex)
    {

        if(startIndex == endIndex)
        {
            if(nums[startIndex] == target)
                return startIndex;
            return -1;
        }

        if(startIndex > endIndex)
            return -1;

        if(nums[endIndex] == target)
            return endIndex;

        int middleIndex = (endIndex + startIndex) / 2;

        if(nums[middleIndex] == target)
        {
            if(nums[middleIndex + 1] == target)
            {
                return getMaxIndex(nums, target, middleIndex + 1, endIndex);
            }

            return middleIndex;

        }

        if(nums[middleIndex] > target)
            return getMaxIndex(nums, target, startIndex, middleIndex - 1); 

        return getMaxIndex(nums, target, middleIndex + 1, endIndex); 

    }

    int getMinIndex(vector<int>& nums, int target, int startIndex, int endIndex)
    {

        if(startIndex == endIndex)
        {
            if(nums[startIndex] == target)
                return startIndex;
            return -1;
        }

        if(startIndex > endIndex)
            return -1;

        if(nums[startIndex] == target)
            return startIndex;

        int middleIndex = (endIndex + startIndex) / 2;

        if(nums[middleIndex] == target)
        {
            if(nums[middleIndex - 1] == target)
            {
                return getMinIndex(nums, target, startIndex, middleIndex -1);
            }

            return middleIndex;

        }

        if(nums[middleIndex] > target)
            return getMinIndex(nums, target, startIndex, middleIndex - 1); 

        return getMinIndex(nums, target, middleIndex + 1, endIndex); 

    }


    vector<int> searchRange(vector<int>& nums, int target) {


        /*
        
        Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

        If target is not found in the array, return [-1, -1].

        You must write an algorithm with O(log n) runtime complexity.

        

        Example 1:

        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]
        Example 2:

        Input: nums = [5,7,7,8,8,10], target = 6
        Output: [-1,-1]
        Example 3:

        Input: nums = [], target = 0
        Output: [-1,-1]
        
        
        */


        int n = nums.size();

        if(n == 0)
            return {-1, -1};

        if(n == 1 && target == nums[0])
            return {0, 0};

        int maxIndex = getMaxIndex(nums, target, 0, n - 1);

        if(maxIndex == -1)
            return {-1, -1};

        if(maxIndex == 0)
        {
            return {0, 0};
        }

        if(nums[maxIndex - 1] != target)
            return {maxIndex, maxIndex};

        return {getMinIndex(nums, target, 0, maxIndex - 1), maxIndex};

    }

};