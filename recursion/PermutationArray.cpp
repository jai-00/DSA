#include <iostream>
#include <vector>
// #include <utility>
using namespace std;
void findPermutations(vector<int> &arr, int index, vector<vector<int>> &ans)
{
    if (index >= arr.size())
    {
        ans.push_back(arr);
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        findPermutations(arr, index + 1, ans);
        swap(arr[i], arr[index]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << endl
         << "------------------------" << endl;
    vector<vector<int>> ans;

    findPermutations(arr, 0, ans);
    for (vector<int> perms : ans)
    {
        for (int val : perms)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl
         << "------------------------" << endl;

    return 0;
}