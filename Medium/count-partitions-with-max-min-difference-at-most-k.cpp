
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/?envType=daily-question&envId=2025-12-06

/*

You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

Return the total number of ways to partition nums under this condition.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [9,4,1,3,7], k = 4

Output: 6

Explanation:

There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

[[9], [4], [1], [3], [7]]
[[9], [4], [1], [3, 7]]
[[9], [4], [1, 3], [7]]
[[9], [4, 1], [3], [7]]
[[9], [4, 1], [3, 7]]
[[9], [4, 1, 3], [7]]
Example 2:

Input: nums = [3,3,4], k = 0

Output: 2

Explanation:

There are 2 valid partitions that satisfy the given conditions:

[[3], [3], [4]]
[[3, 3], [4]]
 

Constraints:

2 <= nums.length <= 5 * 104
1 <= nums[i] <= 109
0 <= k <= 109

*/

class Solution {
public:

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;

        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1); // prefix[i] = sum(dp[0... i])
        
        multiset<int> cnt;
        dp[0] = 1;
        prefix[0] = 1;
        
        for (int i = 0, j = 0; i < nums.size(); i++) {
            cnt.emplace(nums[i]);
            // adjust window
            while (j <= i && *cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }
        return dp[n];
    }
};