
// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:

    

    int longestValidParentheses(string s) {
        
        /*
        
        Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.

        Example 1:

        Input: s = "(()"
        Output: 2
        Explanation: The longest valid parentheses substring is "()".
        Example 2:

        Input: s = ")()())"
        Output: 4
        Explanation: The longest valid parentheses substring is "()()".
        Example 3:

        Input: s = ""
        Output: 0
        
        */

        int n = s.size();
        vector<int> closingLocation(n, -1);
        unordered_map<int, int> rankToIndex;

        int rank = 0;

        for(int i = 0 ; i < n; i++)
        {

            if(rank == 0 && s[i] == ')')
                continue;

            if(s[i] == '(')
            {
                rankToIndex[rank++] = i;
            }
            else
            {
                closingLocation[rankToIndex[--rank]] = i;
            }

        }

        int maxRange = 0;

        for(int i = 0; i < n;)
        {

            if(closingLocation[i] == -1)
            {
                i++;
                continue;
            }

            int start = i;

            while(start < n && closingLocation[start] != -1)
            {
                start = closingLocation[start] + 1;
            }

            int currentRange = start - i;

            maxRange = max(maxRange, currentRange);

            i = start;

        }

        return maxRange;

    }
};