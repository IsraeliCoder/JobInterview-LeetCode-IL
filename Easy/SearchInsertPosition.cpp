
// https://leetcode.com/problems/search-insert-position/

class Solution {
public:

    int searchInsertHelper(vector<int>& nums, int target, int minI, int maxI)
    {

        int range = maxI - minI;
        if(range <= 1)
        {
            if(range == 0)
            {
                if(nums[minI] == target)
                    return minI;
                else if(nums[minI] > target)
                    return minI;
                
                return minI + 1;
            }
            else
            {
                if(nums[minI] >= target)
                    return minI;
                else if(nums[maxI] >= target)
                    return maxI;
                
                return maxI + 1;
            }

        }
        
        int middle = (maxI + minI) / 2;

        if(nums[middle] < target)
            return searchInsertHelper(nums, target, middle, maxI);
        else if(nums[middle] > target)
            return searchInsertHelper(nums, target, minI, middle);

        return middle;

    }

    int searchInsert(vector<int>& nums, int target) {
		/*
		
		Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

		You must write an algorithm with O(log n) runtime complexity.

		 

		Example 1:

		Input: nums = [1,3,5,6], target = 5
		Output: 2
		Example 2:

		Input: nums = [1,3,5,6], target = 2
		Output: 1
		Example 3:

		Input: nums = [1,3,5,6], target = 7
		Output: 4
		 

		Constraints:

		1 <= nums.length <= 104
		-104 <= nums[i] <= 104
		nums contains distinct values sorted in ascending order.
		-104 <= target <= 104
		
		*/
        return searchInsertHelper(nums, target, 0, nums.size() - 1);
    }
};