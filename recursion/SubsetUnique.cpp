#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printSubset(vector<int> &arr, int n, vector<int> subsetArr, vector<vector<int>> &ansArray)
{
    if (n >= arr.size())
    {
        ansArray.push_back(subsetArr);
        return;
    }

    subsetArr.push_back(arr[n]);

    n++;
    while (n < arr.size() && arr[n] == arr[n - 1])
    {
        n++;
    }

    // not included
    printSubset(arr, n, subsetArr, ansArray);

    subsetArr.pop_back();
    // included
    printSubset(arr, n, subsetArr, ansArray);
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 3};
    vector<vector<int>> ansArray;
    sort(arr.begin(), arr.end());
    cout << endl
         << "------------------------" << endl;
    printSubset(arr, 0, {}, ansArray);
    for (vector<int> subset : ansArray)
    {
        for (int val : subset)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl
         << "------------------------" << endl;

    return 0;
}