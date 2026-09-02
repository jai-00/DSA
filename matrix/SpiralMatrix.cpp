#include <iostream>
#include <vector>
using namespace std;
void printMatrix(vector<vector<int>> *mat)
{
    for (int i = 0; i < (*mat).size(); i++)
    {
        for (int j = 0; j < (*mat)[i].size(); j++)
        {
            cout << (*mat)[i][j] << " ";
        }
        cout << endl;
    }
}
void printSpiral(vector<vector<int>> *mat)
{
    if ((*mat).empty())
        return;

    int startRow = 0, startCol = 0;
    int endRow = (*mat).size() - 1, endCol = (*mat)[0].size() - 1;

    // while (endCol - startCol > 0 || endRow - startRow > 0)
    {
        for (int i = startCol; i <= endCol; i++)
        {
            cout << (*mat)[startRow][i] << " ";
        }

        for (int i = startRow + 1; i <= endRow; i++)
        {
            cout << (*mat)[i][endCol] << " ";
        }

        if (endCol - startCol > 0 && endRow - startRow > 0)
        {
            for (int i = endCol - 1; i >= startCol; i--)
            {
                cout << (*mat)[endRow][i] << " ";
            }
            for (int i = endRow - 1; i > startRow; i--)
            {
                cout << (*mat)[i][startCol] << " ";
            }
        }
        startCol++;
        startRow++;
        endCol--;
        endRow--;
    }
    while (startRow <= endRow && startCol <= endCol)
    {

        // top row
        for (int i = startCol; i <= endCol; i++)
        {
            cout << (*mat)[startRow][i] << " ";
        }
        startRow++;

        for (int i = startRow; i <= endRow; i++)
        {
            cout << (*mat)[i][endCol] << " ";
        }
        endCol--;

        if (startRow <= endRow)
        {
            for (int i = endCol; i >= startCol; i--)
            {
                cout << (*mat)[endRow][i] << " ";
            }
            endRow--;
        }

        if (startCol <= endCol)
        {
            for (int i = endRow; i >= startRow; i--)
            {
                cout << (*mat)[i][startCol] << " ";
            }
            startCol++;
        }
    }
}
int main()
{
    vector<vector<int>> mat = {{1, 4, 6, 10}, {2, 5, 8, 9}, {3, 7, 11, 14}, {12, 13, 15, 16}};
    // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    // vector<vector<int>> mat = {{1}, {2}, {3}, {4}};
    // vector<vector<int>> mat = {{1, 2, 3, 4}};
    cout << endl
         << "------------------------" << endl;
    printMatrix(&mat);
    cout << endl;
    printSpiral(&mat);
    cout << endl
         << "------------------------" << endl;

    return 0;
}
