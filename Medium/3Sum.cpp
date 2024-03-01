
// https://leetcode.com/problems/3sum/

class Solution {
public:



    inline void insertNewBundle(vector<int> toInsert, vector<vector<int>>& toReturn, unordered_map<int, unordered_map<int, set<int>>>& seenMap,
                                unordered_map<int, int>& numsFreq)
    {
        
        sort(toInsert.begin(), toInsert.end());

        if(toInsert[0] == toInsert[1] || toInsert[1] == toInsert[2])
        {
            if(toInsert[1] == 0)
            {
                if(numsFreq[0] < 3)
                    return;
            }
            
            if(numsFreq[toInsert[1]] < 2)
            {
                return;
            }

        }

        if(!seenMap[toInsert[0]][toInsert[1]].count(toInsert[2]))
        {
            toReturn.push_back(toInsert);
            seenMap[toInsert[0]][toInsert[1]].insert(toInsert[2]);
        }

    }

    void sum2(vector<int>& nums, int index, int target, vector<vector<int>>& toReturn, unordered_map<int, unordered_map<int, 
                set<int>>>& seenMap, unordered_map<int, int>& numsFreq)
    {

        int n = nums.size();
        for(int i = index; i < n; i++)
        {
            int num3;
            if( numsFreq.count(num3 = -(target + nums[i])))
            {
                insertNewBundle({target, nums[i], num3}, toReturn, seenMap, numsFreq);
            }
        }

    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        /*
                Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

        Notice that the solution set must not contain duplicate triplets.

        

        Example 1:

        Input: nums = [-1,0,1,2,-1,-4]
        Output: [[-1,-1,2],[-1,0,1]]
        Explanation: 
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are [-1,0,1] and [-1,-1,2].
        Notice that the order of the output and the order of the triplets does not matter.
        Example 2:

        Input: nums = [0,1,1]
        Output: []
        Explanation: The only possible triplet does not sum up to 0.
        Example 3:

        Input: nums = [0,0,0]
        Output: [[0,0,0]]
        Explanation: The only possible triplet sums up to 0.
        */

        // bank of seen bundles map 
        // always insert in increase order   
        unordered_map<int, unordered_map<int, set<int>>> seenMap;
        vector<vector<int>> toReturn;
        unordered_map<int, int> numsFreq;

        // for num in nums
        int n = nums.size();
        for(int i = 0; i < n ; i++)
            numsFreq[nums[i]]++;

        vector<int> newVector;
        for(auto& numFreq : numsFreq)
        {
        
            int numberToInsert = numFreq.first;

            newVector.push_back(numberToInsert);
            if( numFreq.second >= 2)
                newVector.push_back(numberToInsert);

            if (numberToInsert == 0 && numFreq.second > 2)
                newVector.push_back(numberToInsert);


        }

        n = newVector.size();
        for(int i = 0 ; i < n; i++)
            sum2(newVector, i + 1, newVector[i], toReturn, seenMap, numsFreq);  


        return toReturn;
    }
};