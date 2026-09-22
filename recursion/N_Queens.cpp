#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isPlacementPossible(vector<string> &board, int row, int col)
{

    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; j--, i--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < board[i].size(); i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}
void placeNQueens(vector<string> &board, int n, vector<vector<string>> &ans)
{
    if (n >= board[0].size())
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < board[0].size(); i++)
    {

        if (isPlacementPossible(board, n, i))
        {
            board[n][i] = 'Q';
            placeNQueens(board, n + 1, ans);
            board[n][i] = '.';
        }
    }
}
int main()
{
    int boardSize = 5;
    vector<string> board(boardSize, string(boardSize, '.'));

    vector<vector<string>> ans;
    placeNQueens(board, 0, ans);
    cout << endl
         << "------------------------" << endl;

    for (vector<string> str : ans)
    {
        for (string st : str)
        {
            cout << st << endl;
        }
        cout << endl
             << "***********************" << endl;
    }

    cout << endl
         << "------------------------" << endl;

    return 0;
}