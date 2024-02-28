
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
		/*
		
		Given a string s, find the length of the longest substring without repeating characters.
		
		Example 1:

		Input: s = "abcabcbb"
		Output: 3
		Explanation: The answer is "abc", with the length of 3.
		Example 2:

		Input: s = "bbbbb"
		Output: 1
		Explanation: The answer is "b", with the length of 1.
		Example 3:

		Input: s = "pwwkew"
		Output: 3
		Explanation: The answer is "wke", with the length of 3.
		Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
		
		*/
        unordered_map<char, int> charToFreq;
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxSeq = 0;

        while(i < n)
        {
            
            charToFreq[s[i]]++;

            if(charToFreq.size() == i - j + 1)
                maxSeq = max(maxSeq, i - j + 1);

            while(charToFreq.size() < i - j + 1)
            {
                charToFreq[s[j]]--;
                if(charToFreq[s[j]] == 0)
                    charToFreq.erase(s[j]);
                j++;
            }

            i++;

        }

        return maxSeq;
    }

};