
// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        /*

        Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

        

        Example 1:

        Input: nums1 = [1,2,2,1], nums2 = [2,2]
        Output: [2]
        Example 2:

        Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        Output: [9,4]
        Explanation: [4,9] is also accepted.
 

        */

        unordered_map<int, int> helperMap;
        vector<int> toReturn;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i = 0 ; i < n1; i++)
        {
            helperMap[nums1[i]] = 1;
        }

        for(int i = 0; i < n2; i++)
        {
            if(helperMap[nums2[i]] == 1)
            {
                toReturn.push_back(nums2[i]);
                helperMap[nums2[i]]++;
            }
        }

        return toReturn;

    }
};