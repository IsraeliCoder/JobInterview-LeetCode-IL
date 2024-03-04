
// https://leetcode.com/problems/3sum-closest/

class Solution {
public:

    int getCloserNumber(int number1, int number2, int target)
    {
        return (abs(target - number1) < abs(target - number2) ? number1 : number2);
    }
    
    int closestTo(vector<int>& nums, int start, int end, int target)
    {

        if(start == end)
            return nums[start];

        if(start + 1 == end)
            return getCloserNumber(nums[start], nums[end], target);

        int middle =  (start + end) / 2;
        int left = closestTo(nums, start, middle, target);
        int right = closestTo(nums, middle + 1, end, target);

        return getCloserNumber(left, right, target);

    }


    int threeSumClosest(vector<int>& nums, int target) {
        
        /*
        
        Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

        Return the sum of the three integers.

        You may assume that each input would have exactly one solution.

        

        Example 1:

        Input: nums = [-1,2,1,-4], target = 1
        Output: 2
        Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
        Example 2:

        Input: nums = [0,0,0], target = 1
        Output: 0
        Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
        
        
        */

        sort(nums.begin(), nums.end());

        unordered_map<int, int> numFreq;
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n; i++)
        {
            if(++numFreq[nums[i]] == 3)
            {
                closestSum = getCloserNumber(closestSum, 3 * nums[i], target);
            }
        }

        if(closestSum == target)
            return target;

        int p1 = 0;
        int p2 = n - 1;

        while(p1 + 1 < p2)
        {

            int number3 = closestTo(nums, p1 + 1, p2 - 1, target - nums[p1] - nums[p2]);

            int currTarget = nums[p1] + nums[p2] + number3;
            if(currTarget == target)
                return target;

            closestSum = getCloserNumber(closestSum, currTarget, target);

            if(p1 + 2 >= p2)
                break;

            int goRight = nums[p1] + nums[p2 - 1] + closestTo(nums, p1 + 1, p2 -2, target - nums[p1] - nums[p2 - 1]);
            int goLeft = nums[p1 + 1] + nums[p2] + closestTo(nums, p1 + 2, p2 -1, target - nums[p1 + 1] - nums[p2]);

            if(abs(target - goRight) > abs(target - goLeft))
                p1++;
            else
                p2--;

        }

        return closestSum;

    }

};