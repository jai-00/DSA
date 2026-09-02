#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
void printMatrix(const vector<vector<int>> *mat)
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
bool findTarget(const vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();

    int i = 0;
    int j = n - 1;

    while (i < m && j > 0)
    {
        if (mat[i][j] < target)
        {
            i++;
        }
        else if (mat[i][j] > target)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {2, 4, 6, 8}, {9, 11, 13, 15}, {10, 12, 14, 16}};
    cout << endl
         << "------------------------" << endl;
    printMatrix(&mat);
    int target = 20;
    cout << "Is " << target << " present : " << (findTarget(mat, target) ? "Yes" : "No");
    cout << endl
         << "------------------------" << endl;

    return 0;
}