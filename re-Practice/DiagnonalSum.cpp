#include <iostream>
#include <vector>

using namespace std;
void printMatrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int calculateDiagonalSum(vector<vector<int>> mat, int row)
{
    int sum = 0;

    for (int i = 0; i < row; i++)
    {
        sum += mat[i][i];
        if (i != row - 1 - i)
        {

            sum += mat[i][row - 1 - i];
        }
    }
    return sum;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int rows = 4;
    cout << endl;
    cout << "------------------------" << endl;
    printMatrix(mat);
    int sum = calculateDiagonalSum(mat, rows);
    cout << "\nDiagonal Sum : " << sum << endl;
    cout << "------------------------" << endl;

    return 0;
}