
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:

    int stringEqual(string& bigString, int start, string& small)
    {
        
        int n = small.size();

        if(bigString.size() - start - n < 0)
            return -1;

        for(int i = 0; i < n; i++)
            if(bigString[start + i] != small[i])
                return -1;

        return start;

    }

    int strStr(string haystack, string needle) {
        
        /*
        
        Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

        Example 1:

        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6.
        The first occurrence is at index 0, so we return 0.
        Example 2:

        Input: haystack = "leetcode", needle = "leeto"
        Output: -1
        Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
        
        */
        
        int n = haystack.size();
        int needleSize = needle.size();

        for(int i = 0; i <= n - needleSize; i++)
        {
            int index = stringEqual(haystack, i, needle);
            if(index != -1)
                return index;
        }

        return -1;

    }
};