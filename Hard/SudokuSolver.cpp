
// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    
    set<char> block[3][3];
    set<char> row[9];
    set<char> col[9];

     bool trySolve(vector<vector<char>>& board)
     {
        
        int minSize = INT_MAX;
        int topI = -1, topJ = -1;

        for(int i = 0; i < 9; i++)
        {
            int sizeI = row[i].size();
            if(sizeI == 0)
                continue;

            for(int j= 0; j < 9; j++)
            {

                if(board[i][j] != '.')
                    continue;

                int cnt = 0;
                int _i = i / 3;
                int _j = j / 3;

                int sizeJ = col[j].size();
                int sizeBlock = block[_i][_j].size();

                if(sizeJ == 0 || sizeBlock == 0)
                    continue;

                auto countValids = [&](set<char>& s1, set<char>& s2, set<char>& s3) -> int 
                {
                    int cnt = 0;
                    for(char c : s1)
                    {
                        if(s2.count(c) && s3.count(c))
                        {
                            cnt++;
                        }
                    }
                    return cnt;
                };

                if(sizeI <= min(sizeJ, sizeBlock))
                {
                    cnt = countValids(row[i], col[j], block[_i][_j]);
                }
                else if(sizeJ <= min(sizeI, sizeBlock))
                {
                    cnt = countValids(col[j], row[i], block[_i][_j]);
                }
                else
                {
                    cnt = countValids(block[_i][_j], row[i], col[j]);
                }

                if(cnt == 0)
                    return false;

                if(cnt < minSize)
                {
                    minSize = cnt;
                    topI = i;
                    topJ = j;
                }

            }
        }

        if (minSize == INT_MAX) return true;

        int _top_i = topI / 3, _top_j = topJ / 3;

        for (char num = '1'; num <= '9'; num++) {
            bool existed_blocks = block[_top_i][_top_j].count(num);
            bool existed_rows = row[topI].count(num);
            bool existed_cols = col[topJ].count(num);

            if (existed_blocks && existed_rows && existed_cols) {
                if (existed_blocks) block[_top_i][_top_j].erase(num);
                if (existed_rows) row[topI].erase(num);
                if (existed_cols) col[topJ].erase(num);

                board[topI][topJ] = num;

                bool done = trySolve(board);

                if (done) {
                    return true;
                }

                if (existed_blocks) block[_top_i][_top_j].insert(num);
                if (existed_rows) row[topI].insert(num);
                if (existed_cols) col[topJ].insert(num);
                board[topI][topJ] = '.';
            }
        }
        return false;

     }

    void init(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            row[i].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
            col[i].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j  = 0; j < 3; j++ )
            {
                block[i][j].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
            }
        }

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    block[i/3][j/3].erase(board[i][j]);
                    row[i].erase(board[i][j]);
                    col[j].erase(board[i][j]);
                }
            }
        }

    }

    void solveSudoku(vector<vector<char>>& board) {

        init(board);
        trySolve(board);

    }
};

/*

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char num)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == num || board[i][col] == num)
                return false;
        }

        int stRow = row / 3 * 3;
        int stCol = col / 3 * 3;

        for(int i = stRow; i < stRow + 3; i++)
        {
            for(int j = stCol; j < stCol + 3; j++)
            {
                if(board[i][j] == num)
                    return false;
            }
        } 

        return true;

    }

    bool solveSudoku(vector<vector<char>>& board) {

        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                if(board[row][col] == '.')
                {
                    for(char num = '1'; num <= '9'; num++)
                    {
                        if(isValid(board, row, col, num))
                        {
                            board[row][col] = num;
                            if(solveSudoku(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;

    }
};

*/