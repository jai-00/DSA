#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
pair<int, int> findPair(const vector<int> &nums, const int &expSum)
{
    pair<int, int> ans = {-1, -1};
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int sec = expSum - first;

        if (map.find(sec) != map.end())
        {
            ans.first = i;
            ans.second = map[sec];
        }
        map[first] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 7, 8, 1, 5};
    int expSum = 11;
    cout << endl
         << "------------------------" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    pair<int, int> ans = findPair(nums, expSum);
    cout << "Address " << ans.first << " and address " << ans.second << " will make the expected sum of " << expSum;
    cout << endl
         << "------------------------" << endl;

    return 0;
}