
// https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-03-15

class Solution {
public:

    int maxPossability(int i, int j1, int j2, vector<vector<vector<int>>>& arr, vector<vector<int>>& grid, int n2)
    {
        
        int maxValuePossability = -1;
        int addingElement = grid[i][j1];
        if(j1 != j2)
            addingElement += grid[i][j2];

        for(int _i = -1; _i <= 1; _i++)
        {
            if(j1 + _i < 0 || j1 + _i >= n2)
                continue;

            for(int _j = -1; _j <= 1; _j++)
            {
                if(j2 + _j < 0 || j2 + _j >= n2)
                    continue;

                maxValuePossability = max(maxValuePossability, arr[i+1][j1 + _i][j2 + _j] + addingElement);

            }
        }

        return maxValuePossability;

    }

    int cherryPickup(vector<vector<int>>& grid) {

        /*
        
        You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

        You have two robots that can collect cherries for you:

        Robot #1 is located at the top-left corner (0, 0), and
        Robot #2 is located at the top-right corner (0, cols - 1).
        Return the maximum number of cherries collection using both robots by following the rules below:

        From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
        When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
        When both robots stay in the same cell, only one takes the cherries.
        Both robots cannot move outside of the grid at any moment.
        Both robots should reach the bottom row in grid.
        

        Example 1:


        Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
        Output: 24
        Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
        Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
        Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
        Total of cherries: 12 + 12 = 24.
        Example 2:


        Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
        Output: 28
        Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
        Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
        Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
        Total of cherries: 17 + 11 = 28.
        
        */

        int n1 = grid.size();
        int n2 = grid[0].size();

        vector<vector<vector<int>>> arr(n1, vector<vector<int>>(n2, vector<int>(n2)));

        for(int i = n1 -1; i >= 0; i--)
        {
            for(int j1 = 0; j1 < n2; j1++)
            {
                for(int j2 = 0; j2 < n2; j2++)
                {
                    if(i == n1 - 1)
                    {
                        if(j1 == j2)
                            arr[i][j1][j2] = grid[i][j1];
                        else
                            arr[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    }
                    else
                    {
                        arr[i][j1][j2] = maxPossability(i, j1, j2, arr, grid, n2);
                    }
                }
            }
        }

        return arr[0][0][n2-1];

    }
};