// https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919

#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &sudoku, int val, int row, int col)
{
    // row and col check
    for (int i = 0; i < sudoku.size(); i++)
    {
        if (sudoku[row][i] == val)
            return false;

        if (sudoku[i][col] == val)
            return false;

        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    for (int i = 0; i < sudoku.size(); i++)
    {
        for (int j = 0; j < sudoku.size(); j++)
        {
            if (sudoku[i][j] == 0)
            {
                for (int val = 1; val < 10; val++)
                {
                    if (safe(sudoku, val, i, j))
                    {
                        sudoku[i][j] = val;
                        if (solve(sudoku))
                            return true;
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}