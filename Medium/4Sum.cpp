
// https://leetcode.com/problems/4sum/

class Solution {
public:


    void twoSum(vector<int>& nums, int start, long long target, vector<int>& container, vector<vector<int>>& result)
    {

        int n = nums.size();
        int low = start;
        int high = n - 1;

        while(low < high)
        {

            long long sum = (long long)nums[low] + (long long)nums[high];
            if(sum < target || (low > start && nums[low] == nums[low - 1]))
                low++;
            else if(sum > target || (high < n - 1 && nums[high] == nums[high + 1]))
                high--;
            else
            {
                container.push_back(nums[low]);
                container.push_back(nums[high]);
                result.push_back(container);
                container.pop_back();
                container.pop_back();
                low++;
                high--;
            }

        }

    }

    void kSum(vector<int>& nums, int k, int start, long long target, vector<int>& container, vector<vector<int>>& result)
    {
        
        int n = nums.size();
        if(start == n) 
            return;
        else if(n - start < k) 
            return;
        else if((long long)nums[start] > target / (long long)k)
            return;
        else if((long long)nums[n - 1] < target / (long long)k)
            return;

        if(k == 2){
            twoSum(nums, start, target, container, result);
        }
        else
        {
             for(int i = start; i < n - k + 1; i++)
             {
                 container.push_back(nums[i]);
                 kSum(nums, k - 1, i + 1,  target - (long long)nums[i], container, result);
                 container.pop_back();
                 while(i + 1 < n && nums[i] == nums[i+1])
                    i++;
             }
        }

    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        /*
        
        Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

        0 <= a, b, c, d < n
        a, b, c, and d are distinct.
        nums[a] + nums[b] + nums[c] + nums[d] == target
        You may return the answer in any order.

        

        Example 1:

        Input: nums = [1,0,-1,0,-2,2], target = 0
        Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
        Example 2:

        Input: nums = [2,2,2,2,2], target = 8
        Output: [[2,2,2,2]]
        
        */

        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> container;
        kSum(nums, 4, 0, target, container, results);
        return results;

    }


};