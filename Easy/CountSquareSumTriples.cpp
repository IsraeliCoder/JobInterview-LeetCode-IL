
// https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08

/*

A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.



Example 1:

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
Example 2:

Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).


Constraints:

1 <= n <= 250

*/

class Solution {
public:

    int AddCount(int a, int b, int n)
    {

        int c = a + b;

        int tempC = sqrt(c);

        if (tempC > n)
            return 0;

        if (tempC * tempC == c)
        {

            std::cout << a << ", " << b << std::endl;

            if (a == b)
                return 1;
            return 2;

        }

        return 0;


    }

    int countTriples(int n) {

        int toReturn = 0;

        for (int i = 1; i <= n; i++)
        {

            int a = i * i;
            int b = a;

            toReturn += AddCount(a, b, n);


            for (int j = i + 1; j <= n; j++)
            {

                b = j * j;
                toReturn += AddCount(a, b, n);

            }


        }

        return toReturn;


    }
};