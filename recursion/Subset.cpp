#include <iostream>
#include <vector>
using namespace std;
void printSubset(vector<int> &arr, int n, vector<int> subsetArr)
{
    if (n == arr.size())
    {
        cout << "[ ";
        for (int i = 0; i < subsetArr.size(); i++)
        {
            cout << subsetArr[i] << " ";
        }
        cout << "],";
        return;
    }

    // not included
    printSubset(arr, n + 1, subsetArr);

    // included
    subsetArr.push_back(arr[n]);
    printSubset(arr, n + 1, subsetArr);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << endl
         << "------------------------" << endl;
    printSubset(arr, 0, {});
    cout << endl
         << "------------------------" << endl;

    return 0;
}