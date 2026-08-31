#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
bool findElement(vector<vector<int>> *mat, int *target)
{
    int startRow = 0;
    int endRow = (*mat).size() - 1;
    while (startRow <= endRow)
    {
        int midRow = startRow + ((endRow - startRow) / 2);
        if (*target >= (*mat)[midRow][0] && *target <= (*mat)[midRow][(*mat)[midRow].size() - 1])
        {
            int startCol = 0, endCol = (*mat)[midRow].size() - 1;
            while (startCol <= endCol)
            {
                int midCol = startCol + ((endCol - startCol) / 2);

                if (*target > (*mat)[midRow][midCol])
                {
                    startCol = midCol + 1;
                }
                else if (*target < (*mat)[midRow][midCol])
                {
                    endCol = midCol - 1;
                }
                else
                {
                    return true;
                }
            }
        }
        else if (*target < (*mat)[midRow][0])
        {
            endRow = midRow - 1;
        }
        else
        {
            startRow = midRow + 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << endl
         << "------------------------" << endl;
    printMatrix(&mat);
    int target = 10;
    cout << "Element Found : " << findElement(&mat, &target);
    cout << endl
         << "------------------------" << endl;

    return 0;
}