
// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:

    inline char getNextChar(string& s, int& p1, bool up)
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
    
    bool isPalindrome(string& s, int i, int j) {

        int p1 = i;
        int p2 = j;


        while(p1 < p2)
        {

            if(getNextChar(s, p1, true) != getNextChar(s, p2, false))
                return false;

            p1++;
            p2--;

        }

        return true;

    }

    bool validPalindrome(string s) {
		
		/*
		
		Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

		Example 1:

		Input: s = "aba"
		Output: true
		Example 2:

		Input: s = "abca"
		Output: true
		Explanation: You could delete the character 'c'.
		Example 3:

		Input: s = "abc"
		Output: false
		
		*/
		
        int p1 = 0;
        int p2 = s.size() - 1;

        while(p1 < p2)
        {
            if(s[p1] != s[p2])
            {
                return isPalindrome(s, p1 + 1, p2) || isPalindrome(s, p1, p2 - 1);
            }

            p1++;
            p2--;
        }

        return true;

    }
};