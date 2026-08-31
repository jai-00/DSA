#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
pair<int, int> findElement(int mat[4][3], int row, int col, int searchElement)
{
    pair<int, int> cellAddress = {-1, -1};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == searchElement)
            {
                cellAddress = {i, j};
            }
        }
    }
    return cellAddress;
}
void printMatrix(int mat[4][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int mat[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    pair<int, int> cellAddress;
    int searchElement = 0;
    cout << endl;
    cout << "-----------------" << endl;
    printMatrix(mat, 4, 3);
    cout << "\nEnter element to find: ";
    cin >> searchElement;
    cellAddress = findElement(mat, 4, 3, searchElement);
    cout << endl
         << cellAddress.first << " " << cellAddress.second << endl;
    cout << "-----------------" << endl;
    return 0;
}
