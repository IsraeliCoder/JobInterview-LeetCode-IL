
// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void generateParenthesisHelper(int open, int close, int max, string container, vector<string>& results)
    {

        if(open == close + 1 && open == max)
            results.push_back(container + ")");

        if(open == close)
        {
            generateParenthesisHelper(open + 1, close, max, container + "(", results);
            return;
        }

        if(open > max)
            return;

        generateParenthesisHelper(open + 1, close, max, container + "(", results);
        generateParenthesisHelper(open, close + 1, max, container + ")", results);

    }
    
    vector<string> generateParenthesis(int n) {

        /*
        
        Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

        Example 1:

        Input: n = 3
        Output: ["((()))","(()())","(())()","()(())","()()()"]
        Example 2:

        Input: n = 1
        Output: ["()"]
        
        */

        vector<string> results;

        generateParenthesisHelper(1, 0, n, "(", results);

        return results;

    }
};