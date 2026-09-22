#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printSubset(vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &ansArray)
{
    ansArray.push_back(current);

    for (int i = index; i < arr.size(); i++)
    {

        current.push_back(arr[i]);

        printSubset(arr, i + 1, current, ansArray);

        current.pop_back();
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<vector<int>> ansArray;
    vector<int> current;
    sort(arr.begin(), arr.end());
    cout << endl
         << "------------------------" << endl;
    printSubset(arr, 0, current, ansArray);
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