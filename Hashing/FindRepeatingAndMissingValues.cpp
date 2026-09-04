#include <iostream>
#include <vector>
#include <unordered_set>
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
pair<int, int> findRepeatingAndMissing(const vector<vector<int>> &mat)
{
    pair<int, int> ans;
    unordered_set<int> set;

    int totalNumberOfElements = mat.size() * mat[0].size();
    int expectedSum = (totalNumberOfElements * (totalNumberOfElements + 1)) / 2;
    int trueSum = 0;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            int currElement = mat[i][j];
            if (set.find(currElement) != set.end())
            {
                ans.second = currElement;
            }
            set.insert(currElement);
            trueSum += currElement;
        }
    }

    // as originalSum - missingElement + duplicateElement = newSum so --> originalSum + duplicateElement - newSum = missingElement
    int missingNumber = expectedSum + ans.second - trueSum;
    ans.first = missingNumber;
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{9, 4, 3}, {5, 8, 6}, {7, 3, 1}};
    cout << endl
         << "------------------------" << endl;
    printMatrix(&nums);
    cout << endl;
    pair<int, int> ans = findRepeatingAndMissing(nums);
    cout << "Duplicate Number: " << ans.second << endl
         << "Missing Number: " << ans.first;
    cout << endl
         << "------------------------" << endl;

    return 0;
}