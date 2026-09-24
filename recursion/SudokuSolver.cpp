#include <iostream>
#include <vector>
using namespace std;
bool isPossible(int value, int row, int col, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == '0' + value)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == '0' + value)
        {
            return false;
        }
    }

    int stRow = (row / 3) * 3;
    int stCol = (col / 3) * 3;

    for (int i = stRow; i < stRow + 3; i++)
    {
        for (int j = stCol; j < stCol + 3; j++)
        {
            if (board[i][j] == '0' + value)
            {
                return false;
            }
        }
    }

    return true;
}
void solve(vector<vector<char>> &board, bool &isCompleted)
{

    int emptyRow = -1;
    int emptyCol = -1;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1)
            break;
    }
    if (emptyRow == -1)
    {

        isCompleted = true;
        return;
    }
    for (int m = 1; m <= 9; m++)
    {
        if (isPossible(m, emptyRow, emptyCol, board))
        {

            board[emptyRow][emptyCol] = '0' + m;
            solve(board, isCompleted);
            if (isCompleted)
            {
                return;
            }
            board[emptyRow][emptyCol] = '.';
        }
    }
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool isCompleted = false;
    solve(board, isCompleted);
    cout << endl
         << "------------------------" << endl;
    for (vector<char> rows : board)
    {
        for (char ch : rows)
        {
            cout << ch << "  ";
        }
        cout << endl;
    }
    cout << endl
         << "------------------------" << endl;
    return 0;
}