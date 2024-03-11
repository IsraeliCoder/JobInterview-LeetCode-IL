
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:

    string getStringWithCorrectParentheses(string& s)
    {
        stack<char> parentheses;
        string helper = "";

        for(char ch : s)
        {
            if(ch == '(')
            {
                parentheses.push(ch);
            }
            if(ch == ')')
            {
                if(parentheses.size() > 0)
                {
                    parentheses.pop();
                }
                else
                {
                    continue;
                }
            }

            helper += ch;

        }

        return helper;

    }

    void myReverse(string& helper)
    {
        reverse(helper.begin(), helper.end());
        int n = helper.size();

        for(int i = 0 ; i < n; i++)
        {
            if(helper[i] == ')')
                helper[i] = '(';
            else if(helper[i] == '(')
                helper[i] = ')';
        }

    }


    string minRemoveToMakeValid(string s) {
        
        /*
        
        Given a string s of '(' , ')' and lowercase English characters.

        Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

        Formally, a parentheses string is valid if and only if:

        It is the empty string, contains only lowercase characters, or
        It can be written as AB (A concatenated with B), where A and B are valid strings, or
        It can be written as (A), where A is a valid string.
        

        Example 1:

        Input: s = "lee(t(c)o)de)"
        Output: "lee(t(c)o)de"
        Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
        Example 2:

        Input: s = "a)b(c)d"
        Output: "ab(c)d"
        Example 3:

        Input: s = "))(("
        Output: ""
        Explanation: An empty string is also valid.
        
        */

        string helper = getStringWithCorrectParentheses(s);

        myReverse(helper);

        helper = getStringWithCorrectParentheses(helper);
        myReverse(helper);

        return helper;



    }
};