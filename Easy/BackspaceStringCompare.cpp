
// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:

    inline int skipChars(string& s, int i, int counter)
    {

        if (i < 0)
            return -1;
        
        if(s[i] == '#')
            return skipChars(s, i - 1, counter + 1);

        if(counter == 0)
            return i;

        return skipChars(s, i - 1, counter - 1);

    }

    bool backspaceCompare(string s, string t) 
    {
        
        /*
        
        Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

        Note that after backspacing an empty text, the text will continue empty.

        Example 1:

        Input: s = "ab#c", t = "ad#c"
        Output: true
        Explanation: Both s and t become "ac".
        Example 2:

        Input: s = "ab##", t = "c#d#"
        Output: true
        Explanation: Both s and t become "".
        Example 3:

        Input: s = "a#c", t = "b"
        Output: false
        Explanation: s becomes "c" while t becomes "b".

        */

        int i = s.size() - 1;
        int j = t.size() - 1;

        i = skipChars(s, i, 0);
        j = skipChars(t, j, 0);

        while(i >= 0 && j >= 0)
        {

            if(s[i] != t[j])
                return false;

            j--;
            i--;

            i = skipChars(s, i, 0);
            j = skipChars(t, j, 0);

        }

        if(i == -1 && j == -1)
            return true;

        return false;

    }
};