
// https://leetcode.com/problems/minimum-common-value/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        /*

        Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

        Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

        

        Example 1:

        Input: nums1 = [1,2,3], nums2 = [2,4]
        Output: 2
        Explanation: The smallest element common to both arrays is 2, so we return 2.
        Example 2:

        Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
        Output: 2
        Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
        

        */

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 == 0 || n2 == 0)
            return -1;

        
        int p1 = 0;
        int p2 = 0;

        while(p1 < n1 && p2 < n2)
        {
            
            if(nums1[p1] == nums2[p2])
                return nums1[p1];

            if(nums1[p1] < nums2[p2])
                p1++;
            else
                p2++;


        }

        return -1;

    }
};