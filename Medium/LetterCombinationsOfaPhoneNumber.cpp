
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

    Solution()
    {
        for(int i = 2; i <= 9; i++ )
                _map[i] = getStringPossability(i + '0');
    }

    vector<char> getStringPossability(char number)
    {   
        
        int num = number - '0';
        string possabilities = _mapRaw[num];
        return vector(possabilities.begin(), possabilities.end());

    }

    vector<string> getAlCombinations(string& s, vector<char>& charsToAdd)
    {

        int n = charsToAdd.size();
        vector<string> toReturn(n);

        for(int i = 0 ; i < n; i++)
            toReturn[i] = s + charsToAdd[i];

        return toReturn;

    }

    vector<string> letterCombinations(string digits) {

        /*
        
        Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

        A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

        Example 1:

        Input: digits = "23"
        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
        Example 2:

        Input: digits = ""
        Output: []
        Example 3:

        Input: digits = "2"
        Output: ["a","b","c"]
        
        */

        if(digits.size() == 0)
            return {};

        vector<string> runner = {""};
        
        int n = digits.size();

        for(int i = 0; i < n; i++)
        {
            
            vector<char>& charsToAdd = _map[digits[i] - '0'];
            int runner_size = runner.size();
            int runner_of_digits = charsToAdd.size();
            vector<string> nextRunner(runner_size * runner_of_digits);

            for(int j = 0; j < runner_size; j++)
            {
                
                vector<string> tempToAdd = getAlCombinations(runner[j], charsToAdd);

                for(int w = 0; w < runner_of_digits; w++)
                    nextRunner[j * runner_of_digits + w] = tempToAdd[w];


            }

            runner = nextRunner;

        }

        return runner;

    }

    unordered_map<int, vector<char>> _map;

    unordered_map<int, string> _mapRaw = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

};