
 // https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
		/*
		You are given a binary string s that contains at least one '1'.

		You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

		Return a string representing the maximum odd binary number that can be created from the given combination.

		Note that the resulting string can have leading zeros.

		 

		Example 1:

		Input: s = "010"
		Output: "001"
		Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
		Example 2:

		Input: s = "0101"
		Output: "1001"
		Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
		*/
		
		
        map<char, int> charToFrequency = {
            {1, -1},
            {0, 0}
        }; 

        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                charToFrequency[0]++;
            else
                charToFrequency[1]++;
        }


        string toReturn = charToFrequency[1] > 0 ? std::string(charToFrequency[1], '1') : "";
        toReturn +=  charToFrequency[0] > 0 ? std::string(charToFrequency[0], '0') : "";

        toReturn += "1";

        return toReturn;

    }
};