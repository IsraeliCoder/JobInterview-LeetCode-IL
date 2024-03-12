
// https://leetcode.com/problems/next-permutation/

class Solution {
public:

    bool onlyDown(vector<int>& nums)
    {
        int n = nums.size() - 1;
        for(int i = 0 ; i < n; i++)
        {
            if(nums[i] < nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void findClosestNumberButHigherAndSwap(int number, vector<int>& nums, int start)
    {
        int startAt = start;
        int closest = INT_MAX;
        int index = -1;
        int n = nums.size();

        while(start < n)
        {
            if(nums[start] > number)
            {
                if(nums[start] < closest)
                {
                    closest = nums[start];
                    index = start;
                }
            }
            start++;
        }

        swap(nums[startAt - 1], nums[index]);

    }

    void nextPermutation(vector<int>& nums) {
        
        /*
        
        A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

        For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
        The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

        For example, the next permutation of arr = [1,2,3] is [1,3,2].
        Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
        While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
        Given an array of integers nums, find the next permutation of nums.

        The replacement must be in place and use only constant extra memory.
        
        */

        if(onlyDown(nums))
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int p = nums.size() - 1;

        while(p > 1 && nums[p] <= nums[p - 1])
            p--;

        findClosestNumberButHigherAndSwap(nums[p - 1], nums, p);

        sort(nums.begin() + p, nums.end());

    }

};
