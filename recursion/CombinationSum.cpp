#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findCombination(vector<int> &arr, int target, vector<vector<int>> &ans, int sum, vector<int> &currAns, int currIndex)
{
    if (sum == target)
    {
        ans.push_back(currAns);
        return;
    }

    if (currIndex >= arr.size() || sum + arr[currIndex] > target)
    {
        return;
    }

    currAns.push_back(arr[currIndex]);
    findCombination(arr, target, ans, sum + arr[currIndex], currAns, currIndex);
    currAns.pop_back();

    findCombination(arr, target, ans, sum, currAns, currIndex + 1);
}
int main()
{
    vector<int> arr = {2, 3, 5};
    int target = 8;
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> currAns;
    findCombination(arr, target, ans, 0, currAns, 0);
    cout << endl
         << "------------------------" << endl;
    for (auto &el : ans)
    {
        for (int val : el)
        {
            cout << val << " ";
        }
        cout << "      ";
    }
    cout << endl
         << "------------------------" << endl;

    return 0;
}