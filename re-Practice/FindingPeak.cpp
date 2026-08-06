#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int findPeak(const vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int mid = i + ((j - i) / 2);
        if (nums[mid] < nums[mid + 1])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return i;
}

int main()
{
    vector<int> nums = {1, 2, 4, 8, 5, 2};
    int peak = findPeak(nums);
    cout << "---------" << endl;
    cout << "Peak found : " << nums[peak] << endl;
    cout << "---------" << endl;
    return 0;
}