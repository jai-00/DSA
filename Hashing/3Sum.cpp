#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
vector<vector<int>> findTriplets(vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int a = arr[i];
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k)
        {
            int b = arr[j];
            int c = arr[k];
            if (b + c == -a)
            {
                ans.push_back({a, b, c});

                while (j < k && arr[j] == arr[j + 1])
                {
                    j++;
                }

                while (j < k && arr[k] == arr[k - 1])
                {
                    k--;
                }

                j++;
                k--;
            }
            else if (b + c > -a)
            {
                k--;
            }
            else if (b + c < -a)
            {
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 0, 1, -1, 2};
    vector<vector<int>> ans = findTriplets(arr);
    cout << endl
         << "------------------------" << endl
         << endl;

    for (vector<int> vec : ans)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << (i == vec.size() - 1 ? " = 0" : " + ");
        }
        cout << endl
             << endl;
    }
    cout
        << "------------------------" << endl;

    return 0;
}