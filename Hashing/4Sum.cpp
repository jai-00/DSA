#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> findQuadruplets(vector<int> arr, int tar)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size() - 3; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }

            int m = j + 1;
            int n = arr.size() - 1;

            while (m < n)
            {
                int sum = arr[i] + arr[j] + arr[m] + arr[n];
                if (sum > tar)
                {
                    n--;
                }
                else if (sum < tar)
                {
                    m++;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[m], arr[n]});

                    while (m < n && arr[m] == arr[m + 1])
                        m++;
                    while (m < n && arr[n] == arr[n - 1])
                        n--;

                    m++;
                    n--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, -1, -2, -3, 0};
    int targetSum = 4;
    vector<vector<int>> ans = findQuadruplets(arr, targetSum);
    cout << endl
         << "------------------------" << endl
         << endl;
    cout << "Target Sum = " << targetSum << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << (j < ans[i].size() - 1 ? " + " : " ");
        }
        cout << endl;
    }
    cout << endl
         << "------------------------" << endl;

    return 0;
}