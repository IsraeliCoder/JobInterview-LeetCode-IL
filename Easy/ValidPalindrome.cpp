
// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:

    char getNextChar(string& s, int& p1, bool up)
    {
        
        if(p1 < 0 || p1 > s.size())
            return 0;

        char c = s[p1];
        if( 'A' <= c && c <= 'Z')
            c += -'A' + 'a';

        if(('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
            return c;

        return getNextChar(s, up ? ++p1 : --p1, up);
        
    }
    
    bool isPalindrome(string s) {
        
        /*
        
        A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

        Given a string s, return true if it is a palindrome, or false otherwise.

        

        Example 1:

        Input: s = "A man, a plan, a canal: Panama"
        Output: true
        Explanation: "amanaplanacanalpanama" is a palindrome.
        Example 2:

        Input: s = "race a car"
        Output: false
        Explanation: "raceacar" is not a palindrome.
        Example 3:

        Input: s = " "
        Output: true
        Explanation: s is an empty string "" after removing non-alphanumeric characters.
        Since an empty string reads the same forward and backward, it is a palindrome.
        
        */

        int p1 = 0;
        int p2 = s.size() - 1;


        while(p1 < p2)
        {

            if(getNextChar(s, p1, true) != getNextChar(s, p2, false))
                return false;

            p1++;
            p2--;

        }

        return true;

    }
};