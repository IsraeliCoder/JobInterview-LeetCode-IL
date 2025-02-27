
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

//f(x) = f(x-1) + f(x-2)
// 1, 1, 2, 3, 5, 8, 13, 21, 34

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        /*

        A sequence x1, x2, ..., xn is Fibonacci-like if:

        n >= 3
        xi + xi+1 == xi+2 for all i + 2 <= n
        Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

        A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].



        Example 1:

        Input: arr = [1,2,3,4,5,6,7,8]
        Output: 5
        Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
        Example 2:

        Input: arr = [1,3,7,11,12,14,18]
        Output: 3
        Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].


        Constraints:

        3 <= arr.length <= 1000
        1 <= arr[i] < arr[i + 1] <= 109

        */

        unordered_set<int> bank;
        unordered_map<int, unordered_set<int>> partOfFib;

        for (int num : arr)
        {
            bank.insert(num);
            partOfFib[num] = {};
        }

        int longest = 0;
        int size = arr.size();
        for (int i = 0; i < size - longest + 1; i++)
        {
            for (int j = i + 1; j < size - longest + 1; j++)
            {
                int tempLength = 3;

                int searchFor = arr[i] + arr[j];
                if (bank.count(searchFor) == 0 || partOfFib[i].count(j) == 1)
                {
                    continue;
                }

                partOfFib[i].insert(j);
                partOfFib[j].insert(searchFor);

                int a = arr[j];
                int b = searchFor;

                while (bank.count(a + b) == 1)
                {
                    int temp = b;
                    b = a + b;
                    a = temp;
                    tempLength++;
                    partOfFib[a].insert(b);

                }

                longest = max(longest, tempLength);

            }
        }

        return longest;

    }
};