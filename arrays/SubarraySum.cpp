#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findSubArray(vector<int> &arr, int &target)
{
    int ans = 0, sum = 0;

    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int reqValue = sum - target;
        if (map.find(reqValue) != map.end())
        {
            ans += map[reqValue];
        }
        map[sum]++;
    }
    return ans;
}
int main()
{
    // vector<int> arr = {9, 4, 20, 3, 10, 5};
    // vector<int> arr = {1, 1, 1};
    vector<int> arr = {5, -2, 3};
    int targetSum = 3;
    int ans = findSubArray(arr, targetSum);
    cout << endl
         << "------------------------" << endl
         << endl;
    cout << "Possible subarrays: " << ans;
    cout << endl
         << "------------------------" << endl;

    return 0;
}