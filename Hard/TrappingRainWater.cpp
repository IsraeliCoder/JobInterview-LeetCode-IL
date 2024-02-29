
// https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        
        /*
        
        Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

        Example 1:


        Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
        Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
        Example 2:

        Input: height = [4,2,0,3,2,5]
        Output: 9
        
        */

        int n = height.size();
        int l = 0;
        int r = n - 1;

        int maxL = height[l];
        int maxR = height[r];

        int totalWater = 0;

        while(l < r)
        {
            if(maxR < maxL)
            {
                r--;
                maxR = max(maxR, height[r]);
                totalWater += maxR - height[r];
            }
            else
            {
                l++;
                maxL = max(maxL, height[l]);
                totalWater += maxL - height[l];
            }
        }

        return totalWater;

    }
};