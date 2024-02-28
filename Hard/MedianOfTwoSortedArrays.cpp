
// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        /*
        
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

        The overall run time complexity should be O(log (m+n)).

        

        Example 1:

        Input: nums1 = [1,3], nums2 = [2]
        Output: 2.00000
        Explanation: merged array = [1,2,3] and median is 2.
        Example 2:

        Input: nums1 = [1,2], nums2 = [3,4]
        Output: 2.50000
        Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
        
        */

        /*

            O(nlogn)

            vector<int> merged(nums1.size() + nums2.size());

            merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

            sort(merged.begin(), merged.end());

            int n = merged.size();

            if(n % 2 == 1)
                return merged[n / 2];

            return (merged[n / 2] + merged[(n / 2) - 1]) / 2.0;
        
        */


        /*

        O(n)
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int abstractMiddle = ((n1 + n2) / 2) + 1;

        vector<int> container(abstractMiddle);

        int p1 = 0;
        int p2 = 0;

        for(int i = 0 ; i< abstractMiddle; i++)
        {

            int num1 = p1 < n1 ? nums1[p1] : INT_MAX;
            int num2 = p2 < n2 ? nums2[p2] : INT_MAX;

            if(num1 < num2)
            {
                container[i] = num1;
                p1++;
            }  
            else
            {
                container[i] = num2;
                p2++;
            }

        }

        if((n1 + n2) % 2 == 1)
            return container[abstractMiddle - 1];

        return (container[abstractMiddle - 1] + container[abstractMiddle - 2]) / 2.0;

        */



        // O(log(n))

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) 
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0;
        int end = n1;

        int realMiddle = (n1 + n2 + 1) / 2;

        while(start <= end)
        {

            int leftMiddle = (start + end) / 2;
            int rightMiddle = (realMiddle - leftMiddle);

            int left1, left2, right1, right2;

            left1 = leftMiddle > 0 ? nums1[leftMiddle - 1] : INT_MIN;
            left2 = rightMiddle > 0 ? nums2[rightMiddle - 1] : INT_MIN;

            right1 = leftMiddle < n1 ? nums1[leftMiddle] : INT_MAX;
            right2 = rightMiddle < n2 ? nums2[rightMiddle] : INT_MAX;

            if(left1 <= right2 && left2 <= right1)
            {
                if((n1 + n2) % 2 == 1)
                {
                    return max(left1, left2);
                }
                else
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
            else if(left1 > right2)
            {
                end = leftMiddle - 1;
            }
            else
            {
                start = leftMiddle + 1;
            }

        }

        return -1;

    }

};