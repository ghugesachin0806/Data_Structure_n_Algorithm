// https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286

#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &boards, int col, int row)
{
    int temp = col;
    // row checking
    while (temp > 0)
    {
        temp--;
        if (boards[row][temp] == 1)
            return false;
    }

    // upper diagonal checking
    int temprow = row;
    int tempcol = col;
    while (tempcol > 0 && temprow > 0)
    {
        temprow--;
        tempcol--;
        if (boards[temprow][tempcol] == 1)
            return false;
    }

    // Lower diagonal
    temprow = row;
    tempcol = col;
    while (tempcol > 0 && temprow < boards.size() - 1)
    {
        temprow++;
        tempcol--;
        if (boards[temprow][tempcol] == 1)
            return false;
    }

    return true;
}
void solve(vector<vector<int>> &board, int col, vector<vector<int>> &ans)
{
    if (col == board.size())
    {
        vector<int> temp;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
                temp.push_back(board[i][j]);
        }
        ans.push_back(temp);
        return;
    }

    for (int row = 0; row < board.size(); row++)
    {
        if (safe(board, col, row))
        {
            board[row][col] = 1;
            solve(board, col + 1, ans);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(board, 0, ans);
    return ans;
}