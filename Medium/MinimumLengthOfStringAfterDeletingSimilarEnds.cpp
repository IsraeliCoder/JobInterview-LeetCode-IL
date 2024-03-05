
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/?envType=daily-question&envId=2024-03-05

class Solution {
public:

    int getStartOfSuffix(string& s, int p2)
    {
        char temp = s[p2];

        while(p2 > 0 && s[p2 - 1] == temp)
            p2--;

        return p2;
    }

    int getEndOfPrefix(string& s, int p1)
    {

        char temp = s[p1];
        int n = s.size() - 1;

        while(p1 < n && s[p1 + 1] == temp)
            p1++;

        return p1;

    }

    int minimumLength(string s) {
        
        /*
        
        Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

        Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
        Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
        The prefix and the suffix should not intersect at any index.
        The characters from the prefix and suffix must be the same.
        Delete both the prefix and the suffix.
        Return the minimum length of s after performing the above operation any number of times (possibly zero times).

        Example 1:

        Input: s = "ca"
        Output: 2
        Explanation: You can't remove any characters, so the string stays as is.
        Example 2:

        Input: s = "cabaabac"
        Output: 0
        Explanation: An optimal sequence of operations is:
        - Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
        - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
        - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
        - Take prefix = "a" and suffix = "a" and remove them, s = "".
        Example 3:

        Input: s = "aabccabba"
        Output: 3
        Explanation: An optimal sequence of operations is:
        - Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
        - Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
        
        */

        int p1 = 0;
        int p2 = s.size() - 1;

        if(p1 == p2)
            return 1;

        while(p1 < p2)
        {
            
            if(s[p1] != s[p2])
                return p2 + 1 - p1;

            if(p1 == p2)
                return 1;

            int p1Next = getEndOfPrefix(s, p1);
            int p2Next = getStartOfSuffix(s, p2);

            p1 = p1Next + 1;
            p2 = p2Next - 1;


        }

        if(p1 == p2)
            return 1;

        return 0;
    }
};