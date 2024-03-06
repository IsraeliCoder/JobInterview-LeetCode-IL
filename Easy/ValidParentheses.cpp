
// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:

   
    bool isValid(string s) {
        
        /*
        
        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

        An input string is valid if:

        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.
        

        Example 1:

        Input: s = "()"
        Output: true
        Example 2:

        Input: s = "()[]{}"
        Output: true
        Example 3:

        Input: s = "(]"
        Output: false
        
        */
      
        set<char> possabilities = {'{', '[', '('};
        unordered_map<char, char> switchs = {
            {'}' , '{'},
            {')', '('},
            {']', '['}
        };

        int n = s.size();

        if(n < 2)
            return false;

        if(n%2 == 1)
            return false;

        stack<char> brackets;

        for(auto& ch : s)
        {
            if(possabilities.count(ch))
            {
                brackets.push(ch);
            }
            else
            {
                if(brackets.size() == 0)
                {
                    return false;
                }

                char temp = brackets.top();
                if(temp != switchs[ch])
                    return false;
                brackets.pop();
            }
        }

        return brackets.size() == 0;

    }
};